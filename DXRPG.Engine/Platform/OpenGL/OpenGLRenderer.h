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

				virtual bool Initialize(const Window& window);
				virtual void SetClearColor(const float & r, const float & g, const float & b, const float & a);
				virtual void Clear();
				virtual void SwapBuffer();
				virtual void Begin_Render();
				virtual void Render();
				virtual void End_Render();
				virtual void Shutdown(const HWND& hwnd);

				virtual void EnableBlend();

				virtual void SetViewport(const float& x, const float& y,
					const float& width, const float& height);
			private:
				HDC	deviceContext;
				HGLRC RenderContext;
			};
		}
	}
}
