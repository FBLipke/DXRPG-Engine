#pragma once
#include <Platform/Platform.h>
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
			public:
				VertexElement(unsigned int type, unsigned int count, bool normalized)
				{
					this->Type = type;
					this->Count = count;
					this->Normalized = normalized;
				}

				static unsigned int Get_SizeOfType(unsigned int type)
				{
					switch (type)
					{
					case GL_FLOAT:				return 4;
					case GL_UNSIGNED_BYTE:		return 1;
					case GL_UNSIGNED_INT:		return 4;
					case GL_BYTE:				return 1;
					}
				}
			};

			class VertexBufferLayout
			{
			public:
				VertexBufferLayout() {};
				virtual ~VertexBufferLayout() {
					elements.clear();
				};

				template<typename T>
				inline void Push(unsigned int count)
				{
					static_assert(false);
				}

				inline void Push(unsigned int count, bool normalized)
				{
					elements.push_back({ GL_FLOAT, count, false });
					stride += count * VertexElement::Get_SizeOfType(GL_FLOAT);
				}

				const std::vector<VertexElement>& Get_Elements() const
				{
					return this->elements;
				}

				unsigned int Get_Stride() const
				{
					return this->stride;
				}

			private:
				std::vector<VertexElement> elements;
				unsigned int stride;
			};
		}
	}
}
