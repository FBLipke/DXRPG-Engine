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
			this->shader->Compile("Assets/Shader/texture.frag", "Assets/Shader/texture.vert", "");

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
				//	x			y			Z		tex-X	tex-Y
					 0.5f,		 0.5f,		0.0f,	 1.0f,	 1.0f,
					 0.5f,		-0.5f,		0.0f,	 1.0f,	 0.0f,
					-0.5f,		 0.5f,		0.0f,	 0.0f,	 1.0f,

				// second triangle
					 0.5f,		-0.5f,		0.0f,	 1.0f,	0.0f,	// bottom right
					-0.5f,		-0.5f,		0.0f,	 0.0f,	0.0f,	// bottom left
					-0.5f,		 0.5f,		0.0f,	 0.0f,	1.0f	// top left
			};


			auto va = new DXRPG::Engine::Renderer::OpenGLVertexArray(vertices, sizeof(vertices));
			auto tex = new DXRPG::Engine::Renderer::OpenGLTexture("Assets/Texture/walk_Brendan.png");


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
						tex->Bind();
						shader->Bind();
						
						shader->setInt("pTexture", 0);
						shader->setMat4("proj", camera->Get_ProjectionViewMatrix());

						va->Render();
						shader->Unbind();

						this->End_Render();
					}

					this->CalculateFPS(deltaTime);

					prevTIme = curTIme;
				}
			}
			delete va;
			Shutdown();
		}
	}
}
