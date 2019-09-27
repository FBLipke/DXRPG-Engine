#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			OpenGLVertexArray::OpenGLVertexArray(const float * vertPositions, int vertCount)
			{
				mVertexCount = vertCount / 5;
				
				glGenBuffers(1, &mVBO);
				glBindBuffer(GL_ARRAY_BUFFER, mVBO);
				glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), vertPositions, GL_STATIC_DRAW);

				glGenVertexArrays(1, &mVAO);
				glBindVertexArray(mVAO);


				
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
				glEnableVertexAttribArray(0);
				
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(3 * sizeof(float)));
				glEnableVertexAttribArray(1);
			}

			OpenGLVertexArray::~OpenGLVertexArray()
			{
				if (mVBO != GL_NONE)
					glDeleteBuffers(1, &mVBO);
				
				if (mVAO != GL_NONE)
					glDeleteVertexArrays(1, &mVAO);
			}

			void OpenGLVertexArray::Render()
			{
				glBindVertexArray(mVAO);
				glDrawArrays(GL_TRIANGLES, 0, mVertexCount);
			}

			void OpenGLVertexArray::AddBuffer(VertexBuffer& buffer, VertexBufferLayout & layout)
			{
				buffer.Bind();
				int offset = 0;

				for (int i = 0; i < layout.Get_Elements().size(); i++)
				{
					glVertexAttribPointer(i, layout.Get_Elements()[i].Count, layout.Get_Elements()[i].Type,
						layout.Get_Elements()[i].Normalized, layout.Get_Stride(), (const void*)offset);

					offset += layout.Get_Elements()[i].Count * layout.Get_Elements()[i].
						Get_SizeOfType(layout.Get_Elements()[i].Type);

					glEnableVertexAttribArray(i);
				}

				buffer.UnBind();
			}
		}
	}
}
