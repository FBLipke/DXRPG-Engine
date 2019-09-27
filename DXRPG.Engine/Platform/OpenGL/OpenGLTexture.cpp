#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			DXRPG::Engine::Renderer::OpenGLTexture::OpenGLTexture(const std::string & path)
			{
				this->path = path;
				stbi_set_flip_vertically_on_load(1);

				glGenTextures(1, &this->id);
				glBindTexture(GL_TEXTURE_2D, this->id);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

				localbuffer = stbi_load(this->path.c_str(), &width, &height, &bpp, 4);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localbuffer);

				if (localbuffer != nullptr)
					stbi_image_free(localbuffer);
				this->localbuffer = nullptr;
				glBindTexture(GL_TEXTURE_2D, 0);
			}

			OpenGLTexture::~OpenGLTexture()
			{
				glDeleteTextures(GL_TEXTURE_2D, &this->id);
			}

			unsigned int OpenGLTexture::Get_TextureId() const
			{
				return this->id;
			}

			void OpenGLTexture::Bind(unsigned int slot) const
			{
				glActiveTexture(GL_TEXTURE0 + slot);
				glBindTexture(GL_TEXTURE_2D, this->id);
			}

			void OpenGLTexture::Unbind() const
			{
				glBindTexture(GL_TEXTURE_2D, 0);
			}

			int OpenGLTexture::Get_Width()
			{
				return this->width;
			}

			int OpenGLTexture::Get_Height()
			{
				return this->height;
			}
		}
	}
}
