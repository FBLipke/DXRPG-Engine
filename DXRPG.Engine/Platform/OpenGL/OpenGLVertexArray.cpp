#include <Platform/Platform.h>

namespace DXRPG::Engine::Renderer
{
	OpenGLVertexArray::OpenGLVertexArray()
	= default;

	OpenGLVertexArray::OpenGLVertexArray(const IndexBuffer* index)
			{
				glGenVertexArrays(1, &mVAO);
			}

			OpenGLVertexArray::~OpenGLVertexArray()
			{
				if (mVAO != 0)
					glDeleteVertexArrays(1, &mVAO);
			}

			void OpenGLVertexArray::Bind()
			{
				glBindVertexArray(mVAO);
			}

			void OpenGLVertexArray::AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout & layout)
			{
				vb = &vertexBuffer;
				glBindVertexArray(mVAO);
				vb->Bind();
				
				unsigned int offset = 0;

				for (unsigned int i = 0; i < layout.Get_Elements().size(); i++)
				{
					glEnableVertexAttribArray(i);
					glVertexAttribPointer(i, layout.Get_Elements()[i].Count, layout.Get_Elements()[i].Type,
						layout.Get_Elements()[i].Normalized, layout.Get_Stride(), reinterpret_cast<const void*>(offset));

					offset += layout.Get_Elements()[i].Count * layout.Get_Elements()[i].Get_SizeOfType(layout.Get_Elements()[i].Type);
				}
			}
}
