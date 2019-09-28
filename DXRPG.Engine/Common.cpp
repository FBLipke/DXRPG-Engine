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
<<<<<<< HEAD
			this->input = new Input();

			this->renderer = new DXRPG::Engine::Renderer::OpenGLRenderer();
			this->camera = new DXRPG::Engine::Renderer::OrthographicCamera(this->window);

=======
			this->renderer = new Renderer::OpenGLRenderer();
			this->camera = new Renderer::OrthographicCamera(this->window);
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc
		}

		Common::~Common()
		{
			delete this->renderer;
			this->renderer = nullptr;

			delete this->shader;
			this->shader = nullptr;

			delete this->input;
			this->input = nullptr;

			delete this->camera;
			this->camera = nullptr;
		}

		bool Common::Inititalize()
		{
			if (!window->Inititalize())
				return false;

			if (!renderer->Initialize(*this->window))
				return false;

<<<<<<< HEAD
			SetWindowLongPtr(this->Get_Window()->GetHWND(), GWLP_USERDATA, (long long)this);

			this->shader = new DXRPG::Engine::Renderer::OpenGLShader();
			this->shader->Compile("Assets/Shader/simple.frag", "Assets/Shader/simple.vert", "");
=======
			this->shader = new Renderer::OpenGLShader();
			this->shader->Compile("Assets/Shader/simple.frag",
				"Assets/Shader/simple.vert", "");
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

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
			case KeyPressed:
				switch (input->Get_PressedKey())
				{
				case 87:
					camera->position.x += 1.5f * 2.5f;
					break;
				case 83:
					camera->position.x -= 2.5f;
					break;
				default:
					break;
				}
				camera->Update(this->Get_Window());
				break;

			case keyReleased:
				input->Set_ReleasedKey(input->Get_PressedKey());
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
			renderer->Begin_Render();
		}

		bool Common::Render()
		{
			renderer->Render();

			return true;
		}

		void Common::End_Render()
		{
			renderer->End_Render();
		}

		Window* Common::Get_Window() const
		{
			return this->window;
		}

		Input * Common::Get_Input()
		{
			return this->input;
		}

		DXRPG::Engine::Renderer::OrthographicCamera * Common::Get_Camera()
		{
			return this->camera;
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

<<<<<<< HEAD
			auto vb = new DXRPG::Engine::Renderer::OpenGLVertexBuffer();
			vb->SetData(vertices, sizeof(vertices));
=======
			auto vb = new Renderer::OpenGLVertexBuffer();
			vb->SetData(vertices, 3 * 4 * sizeof(float));
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

			uint32_t indices[] = { 0, 1, 2, 2, 3, 0 };
			auto ib = new Renderer::OpenGLIndexBuffer();
			ib->SetData(indices, sizeof(indices));

<<<<<<< HEAD
			auto vla = new DXRPG::Engine::Renderer::VertexBufferLayout();


			// x,x,x = 3 <--- this (the colum count) must be passed!
			// x,x,x = 3

			vla->Push(3, false);
=======
			auto vla = new Renderer::VertexBufferLayout();
			vla->Push(4, false);
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

			auto va = new Renderer::OpenGLVertexArray(ib);
			va->AddBuffer(*vb, *vla);

<<<<<<< HEAD
			glm::vec4 color = glm::vec4(camera->GetPosition()->x, camera->GetPosition()->y, camera->GetPosition()->z, 1.0f);
=======
			const glm::vec4 color = glm::vec4(1.0f);
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

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
						shader->Bind();
						shader->setMat4("proj", camera->Get_ProjectionViewMatrix());
						shader->setVec4("color", color);
						va->Bind();
						ib->Bind();

						this->Begin_Render();


						glDrawElements(GL_TRIANGLES, ib->Get_Count(), GL_UNSIGNED_INT, indices);
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
