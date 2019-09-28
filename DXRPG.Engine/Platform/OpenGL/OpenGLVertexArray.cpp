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
				auto elements = layout.Get_Elements();


				for (unsigned int i = 0; i < elements.size(); i++)
				{
					glVertexAttribPointer(i, elements[i].Count, elements[i].Type,
						elements[i].Normalized, layout.Get_Stride(), (const void*)offset);

					glEnableVertexAttribArray(i);
<<<<<<< HEAD
=======
					glVertexAttribPointer(i, layout.Get_Elements()[i].Count, layout.Get_Elements()[i].Type,
						layout.Get_Elements()[i].Normalized, layout.Get_Stride(), reinterpret_cast<const void*>(offset));
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

					offset += elements[i].Count * elements[i].Get_SizeOfType(elements[i].Type);
				}
			}
}
