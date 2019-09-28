#pragma once
#include <Platform/OpenGL/OpenGLRenderer.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			struct VertexElement
			{
				unsigned int Count;
				unsigned int Type;
				unsigned char Normalized;
				VertexElement(unsigned int type, unsigned int count, bool normalized);

				static unsigned int Get_SizeOfType(unsigned int type);
			};

			class VertexBufferLayout final
			{
			public:
				VertexBufferLayout();

				~VertexBufferLayout() {
					elements.clear();
				}

				void Push(unsigned int count, bool normalized)
				{
					elements.emplace_back(GL_FLOAT, count, false);
					stride += count * VertexElement::Get_SizeOfType(GL_FLOAT);
				}

				[[nodiscard]] const std::vector<VertexElement>& Get_Elements() const;

				unsigned int Get_Stride() const;

			private:
				std::vector<VertexElement> elements;
				unsigned int stride;
			};

			inline VertexElement::VertexElement(unsigned type, unsigned count, bool normalized)
			{
				this->Type = type;
				this->Count = count;
				this->Normalized = normalized;
			}

			inline unsigned VertexElement::Get_SizeOfType(unsigned type)
			{
				switch (type)
				{
				case GL_FLOAT: return 4;
				case GL_UNSIGNED_BYTE: return 1;
				case GL_UNSIGNED_INT: return 4;
				case GL_BYTE: return 1;
				default: return 0;
				}
			}

			inline VertexBufferLayout::VertexBufferLayout(): stride(0)
			{
			}

			inline const std::vector<VertexElement>& VertexBufferLayout::Get_Elements() const
			{
				return this->elements;
			}

			inline unsigned VertexBufferLayout::Get_Stride() const
			{
				return this->stride;
			}
		}
	}
}
