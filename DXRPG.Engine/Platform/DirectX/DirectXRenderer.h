#pragma once
#include "../Platform.h"
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT DirectXRenderer
				: public Renderer
			{
			public:
				DirectXRenderer();
				virtual ~DirectXRenderer();

				virtual bool Initialize(const Window& window);
				virtual void Begin_Render();
				virtual void Render();
				virtual void End_Render();
				virtual void Shutdown();

				virtual void SetViewport(const float& x, const float& y,
					const float& width, const float& height);

				virtual void EnableBlend();
			};
		}
	}
}
