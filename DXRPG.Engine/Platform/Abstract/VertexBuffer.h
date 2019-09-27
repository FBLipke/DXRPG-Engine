#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class VertexBuffer
			{
			public:
				VertexBuffer() {};
				virtual ~VertexBuffer() {};

				virtual void SetData(float* data, const int& size) = 0;

				virtual void Bind() = 0;
				virtual void UnBind() = 0;
			};
		}
	}
}
