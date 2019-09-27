#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class OpenGLVertexBuffer :
				public VertexBuffer
			{
			public:
				OpenGLVertexBuffer();
				virtual ~OpenGLVertexBuffer();

				// Geerbt über VertexBuffer
				virtual void SetData(float * data, const int & size) override;
				virtual void Bind() override;
				virtual void UnBind() override;
			};
		}
	}
}
