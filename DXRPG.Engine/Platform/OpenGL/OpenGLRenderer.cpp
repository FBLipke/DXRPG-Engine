#include "../Platform.h"

namespace DXRPG::Engine::Renderer
{


			OpenGLRenderer::OpenGLRenderer()
			{
				this->deviceContext = nullptr;
				this->RenderContext = nullptr;
			}

			OpenGLRenderer::~OpenGLRenderer()
			{
			}

			bool OpenGLRenderer::Initialize(const Window& window)
			{
				this->deviceContext = GetDC(window.GetHwnd());

				{
					PIXELFORMATDESCRIPTOR pfd;
					ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

					pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
					pfd.nVersion = 1;
					pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
					pfd.iPixelType = PFD_TYPE_RGBA;
					pfd.cColorBits = 32;
					pfd.cDepthBits = 24;
					pfd.cStencilBits = 8;

					if (!SetPixelFormat(this->deviceContext, ChoosePixelFormat(this->deviceContext, &pfd), &pfd))
						return OutErrorMsg("Failed to set Pixelformat!");
				}

				const HGLRC tmpRC = wglCreateContext(this->deviceContext);
				if (!wglMakeCurrent(this->deviceContext, tmpRC))
					return OutErrorMsg("Failed to create and activate RENDER context!");

				glewExperimental = 1;

				if (glewInit() != GLEW_OK)
				{
					OutErrorMsg("Failed to initialize GLEW!");
					return false;
				}

				{
					typedef HGLRC(WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC)
						(HDC hDC, HGLRC hShareContext, const int* attributeList);

					const auto wglCreateContextAttribsARB =
						reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));

					if (wglCreateContextAttribsARB != nullptr)
					{
						GLint attributes[] =
						{
							WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
							WGL_CONTEXT_MINOR_VERSION_ARB, 3,
							WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
							0
						};

						this->RenderContext = wglCreateContextAttribsARB(this->deviceContext, nullptr, attributes);
						wglDeleteContext(tmpRC);

						if (!(this->RenderContext && wglMakeCurrent(this->deviceContext, this->RenderContext)))
						{
							OutErrorMsg("Failed to Create OpenGL render context!");
							return false;
						}
					}
					else
					{
						OutErrorMsg("Failed to Create the OpenGL 3.3 Context!\nThe System does not support OpenGL 3.3!");
						return false;
					}
				}

			this->SetViewport(0, 0, window.Get_FrameBufferWidth(), window.Get_FrameBufferHeight());

			this->EnableBlend();
			this->SetClearColor(0.3f, 0.3f, 0.3f, 1.0f);

			return true;
		}

		void OpenGLRenderer::SetClearColor(const float& r, const float& g, const float& b, const float& a)
		{
			glClearColor(r, g, b, a);
		}

		void OpenGLRenderer::Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		}

		void OpenGLRenderer::SwapBuffer()
		{
			SwapBuffers(this->deviceContext);
		}

		void OpenGLRenderer::Begin_Render()
		{
			this->Clear();
		}

		void OpenGLRenderer::Render()
		{
		}

		void OpenGLRenderer::End_Render()
		{
			this->SwapBuffer();
		}

		void OpenGLRenderer::Shutdown(const HWND& hwnd)
		{
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(this->RenderContext);
			ReleaseDC(hwnd, this->deviceContext);
		}

		void OpenGLRenderer::EnableBlend()
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SOURCE0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void OpenGLRenderer::SetViewport(const float & x, const float & y,
			const float& width, const float& height)
		{
			glViewport(static_cast<int>(x), static_cast<int>(y),
				static_cast<int>(width), static_cast<int>(height));
		}
}
