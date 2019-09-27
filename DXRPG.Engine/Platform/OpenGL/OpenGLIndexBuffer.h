#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLIndexBuffer :
				public IndexBuffer
			{
			public:
				OpenGLIndexBuffer();
				virtual ~OpenGLIndexBuffer();

				virtual void SetData(const unsigned int* data, const int& count) override;
				virtual unsigned int Get_Id() const override;
				virtual unsigned int Get_Count() const override;
				virtual void Bind() override;
				virtual void UnBind() override;
			private:
				bool isBound = false;
				unsigned int id = 0;
				unsigned int count = 0;
			};
		}
	}
}
