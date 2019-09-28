#pragma once
#include "Platform\Platform.h"

namespace DXRPG::Engine
{
	Common::Common()
	{
	}

	Common::Common(HINSTANCE hInstance): paused(false)
		{
			this->fps = 0.0f;
			this->window = new Window(hInstance, "Renderer Window");
			this->renderer = new Renderer::OpenGLRenderer();
			this->camera = new Renderer::OrthographicCamera(this->window);
		}

		Common::~Common()
		{
			delete this->renderer;
			this->renderer = nullptr;

			delete this->shader;
			this->shader = nullptr;

			delete this->camera;
			this->camera = nullptr;
		}

		bool Common::Inititalize()
		{
			if (!window->Inititalize())
				return false;

			if (!renderer->Initialize(*this->window))
				return false;

			this->shader = new Renderer::OpenGLShader();
			this->shader->Compile("Assets/Shader/simple.frag",
				"Assets/Shader/simple.vert", "");

			return true;
		}

		bool Common::Start()
		{
			ShowWindow(this->window->GetHwnd(), 1);
			_GameLoop();
			return true;
		}

		bool Common::Event()
		{
			switch (this->window->GetWindowState())
			{
			case Maximized:
				this->renderer->SetViewport(0, 0,
					window->Get_FrameBufferWidth(),
					window->Get_FrameBufferHeight());
				paused = false;
				break;
			case Minimized:
				paused = true;
				break;
			case Restored:
				break;
			case NoState:
				return true;
			case PaintBegin:
				break;
			case PaintEnded:
				break;
			case ResizeBegin:
				paused = true;
				break;
			case Resizing:
				break;
			case ResizeEnd:
				this->renderer->SetViewport(0, 0,
					window->Get_FrameBufferWidth(),
					window->Get_FrameBufferHeight());
				break;
			default:
				break;
			}

			return false;
		}

		bool Common::Update(float dt) const
		{
			this->camera->Update(this->Get_Window());
			return true;
		}

		void Common::Begin_Render()
		{
			this->shader->Bind();
			renderer->Begin_Render();
		}

		bool Common::Render()
		{
			renderer->Render();

			return true;
		}

		void Common::End_Render()
		{
			this->shader->Unbind();
			renderer->End_Render();
		}

		Window* Common::Get_Window() const
		{
			return this->window;
		}

		void Common::CalculateFPS(float dt)
		{
			static int frameCnt = 0;

			static float elapsed = dt;
			frameCnt++;

			if (elapsed >= 1.0f)
			{
				fps = static_cast<float>(frameCnt);
				elapsed = 0.0f;
				frameCnt = 0;
			}
		}

		void Common::Shutdown() const
		{
			renderer->Shutdown(this->window->GetHwnd());
			window->Shutdown();
		}

		void Common::_GameLoop()
		{
			MSG msg = { 0 };

			__int64 prevTIme = 0;
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&prevTIme));

			__int64 countsPerSec = 0;
			QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&countsPerSec));

			const auto secoundsperCount = 1.0f / static_cast<float>(countsPerSec);

			float vertices[] = {
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.5f,  0.5f, 0.0f,
				-0.5f,  0.5f, 0.0f
			};

			auto vb = new Renderer::OpenGLVertexBuffer();
			vb->SetData(vertices, 3 * 4 * sizeof(float));

			uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
			auto ib = new Renderer::OpenGLIndexBuffer();
			ib->SetData(indices, sizeof(indices));

			auto vla = new Renderer::VertexBufferLayout();
			vla->Push(4, false);

			auto va = new Renderer::OpenGLVertexArray(ib);
			va->AddBuffer(*vb, *vla);

			const glm::vec4 color = glm::vec4(1.0f);

			World world;
			world.Generate();
		
			while (WM_QUIT != msg.message)
			{
				if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					__int64 curTIme = 0;
					QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curTIme));
					const float deltaTime = secoundsperCount * (curTIme - prevTIme);
					this->Event();

					if (!paused)
					{
						this->Update(deltaTime);
						this->Begin_Render();
						shader->Bind();
						
						shader->setMat4("proj", camera->Get_ProjectionViewMatrix());
						shader->setVec4("color", color);
						va->Bind();
						ib->Bind();
						glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
						shader->Unbind();

						this->End_Render();
					}

					this->CalculateFPS(deltaTime);

					prevTIme = curTIme;
				}
			}
			delete va;
			delete vb;
			delete ib;
			delete vla;

			Shutdown();
		}
}
