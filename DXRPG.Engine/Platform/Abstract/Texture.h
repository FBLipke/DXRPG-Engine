#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT Texture
			{
			public:
				Texture() {};
				virtual ~Texture() = default;

				virtual unsigned int Get_TextureId() const = 0;
				virtual void Bind(unsigned int slot = 0) const = 0;
				virtual void Unbind() const = 0;
				virtual int Get_Width() = 0;
				virtual int Get_Height() = 0;
			};
		}
	}
}
