#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
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
				auto elements = layout.Get_Elements();


				for (unsigned int i = 0; i < elements.size(); i++)
				{
					glVertexAttribPointer(i, elements[i].Count, elements[i].Type,
						elements[i].Normalized, layout.Get_Stride(), (const void*)offset);

					glEnableVertexAttribArray(i);

					offset += elements[i].Count * elements[i].Get_SizeOfType(elements[i].Type);
				}
			}
		}
	}
}
