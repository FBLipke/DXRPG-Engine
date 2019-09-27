#include "../Platform.h"
#pragma once

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT Renderer
			{
			public:
				Renderer() {};
				virtual ~Renderer() = default;

				virtual bool Initialize(const Window& window) = 0;
				virtual void Begin_Render() = 0;
				virtual void Render() = 0;
				virtual void End_Render() = 0;
				virtual void Shutdown(const HWND& hwnd) = 0;

				virtual void EnableBlend() = 0;
				virtual void SetViewport(const float& x, const float& y,
					const float& width, const float& height) = 0;
			private:

			};
		}
	}
}
