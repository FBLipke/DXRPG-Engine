#include <Platform/Platform.h>

namespace DXRPG::Engine::Renderer
{
			OpenGLVertexBuffer::OpenGLVertexBuffer()
			{
				glGenBuffers(1, &this->id);
				OpenGLVertexBuffer::Bind();
			}

			OpenGLVertexBuffer::~OpenGLVertexBuffer()
			{
				if (this->id != 0)
				{
					OpenGLVertexBuffer::UnBind();
					glDeleteBuffers(1, &this->id);
				}
			}

			void OpenGLVertexBuffer::SetData(const float * data, const unsigned int & size)
			{
				Bind();
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
				UnBind();
			}

			unsigned int OpenGLVertexBuffer::Get_Id() const { return this->id; }

			void OpenGLVertexBuffer::Bind()
			{
				if (this->isBound)
					return;
				
				glBindBuffer(GL_ARRAY_BUFFER, this->id);
			}

			void OpenGLVertexBuffer::UnBind()
			{
				if (!this->isBound)
					return;
				
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}
}
