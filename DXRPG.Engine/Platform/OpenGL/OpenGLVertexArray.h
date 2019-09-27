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

				OpenGLVertexArray(const float* vertPositions, int vertCount);
				virtual ~OpenGLVertexArray();

				virtual void Render();
				virtual void AddBuffer(VertexBuffer & buffer, VertexBufferLayout & layout) override;
			private:
				GLuint mVBO = GL_NONE;
				GLuint mVAO = GL_NONE;

				int mVertexCount = 0;

				// Geerbt über VertexArray

			};

		}
	}
}
