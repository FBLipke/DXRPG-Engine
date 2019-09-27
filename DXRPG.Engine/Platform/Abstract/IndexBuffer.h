#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT IndexBuffer
			{
			public:
				IndexBuffer() {};
				virtual ~IndexBuffer() {};

				virtual void SetData(const unsigned int* data, const int& count) = 0;
				virtual unsigned int Get_Id() const = 0;
				virtual unsigned int Get_Count() const = 0;
				virtual void Bind() = 0;
				virtual void UnBind() = 0;
			};
		}
	}
}
