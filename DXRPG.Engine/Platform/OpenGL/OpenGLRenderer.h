#pragma once
#include "../Platform.h"
#define GLEW_STATIC
#include <gl/glew.h>
#include <gl/wglew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/wglext.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLRenderer :
				public Renderer
			{
			public:
				OpenGLRenderer();
				virtual ~OpenGLRenderer();

				bool Initialize(const Window& window) override;
				virtual void SetClearColor(const float & r, const float & g, const float & b, const float & a);
				virtual void Clear();
				virtual void SwapBuffer();
				void Begin_Render() override;
				void Render() override;
				void End_Render() override;
				void Shutdown(const HWND& hwnd) override;

				void EnableBlend() override;

				void SetViewport(const float& x, const float& y,
					const float& width, const float& height) override;
			private:
				HDC	deviceContext;
				HGLRC RenderContext;
			};
		}
	}
}
