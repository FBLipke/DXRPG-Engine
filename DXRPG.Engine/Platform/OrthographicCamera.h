#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class OrthographicCamera final :
				public Camera
			{
			public:
				explicit OrthographicCamera(Window * w);
				virtual ~OrthographicCamera();

				void Update(Window * w) override;
				glm::mat4& Get_ProjectionViewMatrix() override;

				void SetPosition(const float& x, const float& y, const float& z) override;
			private:
				glm::vec3 position;
				glm::mat4 proj;
				glm::mat4 view;
				glm::mat4 projView;
				glm::mat4 model;
			};
		}
	}
}
