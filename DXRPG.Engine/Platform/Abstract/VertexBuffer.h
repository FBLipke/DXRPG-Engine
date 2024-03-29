#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT VertexBuffer
			{
			public:
				VertexBuffer() {};
				virtual ~VertexBuffer() {};

				virtual void SetData(const float* data, const unsigned int& size) = 0;
				virtual unsigned int Get_Id() const = 0;
				virtual void Bind() = 0;
				virtual void UnBind() = 0;
			};
		}
	}
}
