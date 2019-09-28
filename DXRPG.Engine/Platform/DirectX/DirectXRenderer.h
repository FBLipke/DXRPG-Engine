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

				bool Initialize(const Window& window) override;
				void Begin_Render() override;
				void Render() override;
				void End_Render() override;
				virtual void Shutdown();

				void SetViewport(const float& x, const float& y,
					const float& width, const float& height) override;

				void EnableBlend() override;
			};
		}
	}
}
