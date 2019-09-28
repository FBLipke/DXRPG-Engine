#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			OpenGLIndexBuffer::OpenGLIndexBuffer()
			{
				glGenBuffers(1, &this->id);
			}

			OpenGLIndexBuffer::~OpenGLIndexBuffer()
			{
				if (this->id == 0)
					return;

				UnBind();
				glDeleteBuffers(1, &this->id);
			}

			void OpenGLIndexBuffer::SetData(const unsigned int* data, const int& count)
			{
				this->count = count;

				Bind();
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->count, data, GL_STATIC_DRAW);
			}

			unsigned int OpenGLIndexBuffer::Get_Id() const { return this->id; }
			unsigned int OpenGLIndexBuffer::Get_Count() const { return this->count; }

			void OpenGLIndexBuffer::Bind()
			{
				if (this->isBound)
					return;

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
				this->isBound = true;
			}

			void OpenGLIndexBuffer::UnBind()
			{
				if (!this->isBound)
					return;

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
				this->isBound = false;
			}
		}
	}
}
