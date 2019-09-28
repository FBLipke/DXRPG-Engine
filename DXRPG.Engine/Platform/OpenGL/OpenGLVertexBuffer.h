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

				void SetData(const float * data, const unsigned int & size) override;
				unsigned int Get_Id() const override;
				void Bind() override;
				void UnBind() override;
			private:
				bool isBound = false;
				unsigned int id = 0;
			};
		}
	}
}
