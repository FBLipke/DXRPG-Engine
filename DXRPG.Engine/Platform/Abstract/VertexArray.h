#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT VertexArray
			{
			public:
				VertexArray() {}
				virtual void AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout & layout) = 0;
				VertexArray(const IndexBuffer* index) {};
				virtual ~VertexArray() {};

				virtual void Bind() = 0;
			};
		}
	}
}
