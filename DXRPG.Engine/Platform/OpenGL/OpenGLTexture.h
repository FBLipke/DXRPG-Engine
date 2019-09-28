#pragma once
#include <Platform/Platform.h>
#include <Vendor/stb_image/stb_image.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLTexture final
			{
			public:
				OpenGLTexture();

				explicit OpenGLTexture(const std::string& path);

				~OpenGLTexture();

				unsigned int Get_TextureId() const;
				void Bind(unsigned int slot = 0) const;
				void Unbind() const;
				int Get_Width() const;
				int Get_Height() const;
			private:
				std::string path;
				unsigned int id;
				int width;
				int height;
				int bpp;

				unsigned char* localbuffer = nullptr;
			};
		}
	}
}
