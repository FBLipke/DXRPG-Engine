#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLVertexBuffer :
				public VertexBuffer
			{
			public:
				OpenGLVertexBuffer();
				virtual ~OpenGLVertexBuffer();

				virtual void SetData(const float * data, const unsigned int & size) override;
				virtual unsigned int Get_Id() const override;
				virtual void Bind() override;
				virtual void UnBind() override;
			private:
				bool isBound = false;
				unsigned int id = 0;
			};
		}
	}
}
