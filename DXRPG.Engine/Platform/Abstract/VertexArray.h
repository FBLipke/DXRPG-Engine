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
				virtual void AddBuffer(VertexBuffer& buffer, VertexBufferLayout& layout) = 0;
				VertexArray(const float* vertPositions, int vertCount) {};
				virtual ~VertexArray() {};

				virtual void Render() = 0;
			};
		}
	}
}
