#pragma once
#include "Platform\Platform.h"

namespace DXRPG
{
	namespace Engine
	{
		Common::Common(HINSTANCE hInstance)
		{
			this->fps = 0.0f;
			this->window = new Window(hInstance, "Renderer Window");
			this->renderer = new DXRPG::Engine::Renderer::OpenGLRenderer();
			this->camera = new DXRPG::Engine::Renderer::OrthographicCamera(this->window);
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
			if (!window->Inititalize() || !renderer->Initialize(*this->window))
				return false;

			this->shader = new DXRPG::Engine::Renderer::OpenGLShader();
			this->shader->Compile("Assets/Shader/simple.frag", "Assets/Shader/simple.vert", "");

			return true;
		}

		bool Common::Start()
		{
			ShowWindow(this->window->GetHWND(), 1);
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

		bool Common::Update(float dt)
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
				fps = (float)frameCnt;
				elapsed = 0.0f;
				frameCnt = 0;
			}
		}

		void Common::Shutdown()
		{
			renderer->Shutdown(this->window->GetHWND());
			window->Shutdown();
		}

		void Common::_GameLoop()
		{
			MSG msg = { 0 };

			__int64 prevTIme = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&prevTIme);

			__int64 countsPerSec = 0;
			QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);

			float secoundsperCount = 1.0f / countsPerSec;

			float vertices[] = {
				-0.5f, -0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				 0.5f,  0.5f, 0.0f,
				-0.5f,  0.5f, 0.0f
			};

			auto vb = new DXRPG::Engine::Renderer::OpenGLVertexBuffer();
			vb->SetData(vertices, 3 * 4 * sizeof(float));

			uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
			auto ib = new DXRPG::Engine::Renderer::OpenGLIndexBuffer();
			ib->SetData(indices, sizeof(indices));

			auto vla = new DXRPG::Engine::Renderer::VertexBufferLayout();
			vla->Push(4, false);

			auto va = new DXRPG::Engine::Renderer::OpenGLVertexArray(ib);
			va->AddBuffer(*vb, *vla);

			glm::vec4 color = glm::vec4(1.0f);

			while (WM_QUIT != msg.message)
			{
				if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					__int64 curTIme = 0;
					QueryPerformanceCounter((LARGE_INTEGER*)&curTIme);
					float deltaTime = (curTIme - prevTIme) * secoundsperCount;
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
}
