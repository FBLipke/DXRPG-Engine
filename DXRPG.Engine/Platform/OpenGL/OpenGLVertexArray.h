#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT OpenGLVertexArray :
				public VertexArray
			{
			public:
				OpenGLVertexArray() {};

				OpenGLVertexArray(const IndexBuffer* index);
				virtual ~OpenGLVertexArray();

				virtual void Bind();
				virtual void AddBuffer(VertexBuffer& vertexBuffer, VertexBufferLayout & layout) override;
			private:
				VertexBuffer* vb = nullptr;
				IndexBuffer* ib = nullptr;

				GLuint mVAO = 0;

				int mVertexCount = 0;
			};
		}
	}
}
