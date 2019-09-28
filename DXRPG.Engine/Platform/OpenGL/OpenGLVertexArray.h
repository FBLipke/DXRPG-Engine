#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLVertexArray final :
				public VertexArray
			{
			public:
				OpenGLVertexArray();

				OpenGLVertexArray(const IndexBuffer* index);
				virtual ~OpenGLVertexArray();

				void Bind() override;
				void AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout & layout) override;
			private:
				VertexBuffer* vb = nullptr;

				GLuint mVAO = 0;

				int mVertexCount = 0;
			};
		}
	}
}
