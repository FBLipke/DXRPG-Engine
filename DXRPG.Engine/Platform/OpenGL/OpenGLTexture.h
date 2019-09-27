#include <Platform/Platform.h>
#include <Vendor/stb_image/stb_image.h>
#pragma once

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLTexture
			{
			public:
				OpenGLTexture() {};
				OpenGLTexture(const std::string& path);

				virtual ~OpenGLTexture();

				virtual unsigned int Get_TextureId() const;
				virtual void Bind(unsigned int slot = 0) const;
				virtual void Unbind() const;
				virtual int Get_Width();
				virtual int Get_Height();
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
