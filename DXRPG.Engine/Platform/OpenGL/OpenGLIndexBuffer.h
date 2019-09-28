#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLIndexBuffer final :
				public IndexBuffer
			{
			public:
				OpenGLIndexBuffer();
				virtual ~OpenGLIndexBuffer();

				void SetData(const unsigned int* data, const int& count) override;
				unsigned int Get_Id() const override;
				unsigned int Get_Count() const override;
				void Bind() override;
				void UnBind() override;
			private:
				bool isBound = false;
				unsigned int id = 0;
				unsigned int count = 0;
			};
		}
	}
}
