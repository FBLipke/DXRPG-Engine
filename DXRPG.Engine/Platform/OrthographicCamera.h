#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class OrthographicCamera :
				public Camera
			{
			public:
				OrthographicCamera(Window * w);
				virtual ~OrthographicCamera();

				// Geerbt über Camera
				virtual void Update(Window * w) override;
				virtual glm::mat4& Get_ProjectionViewMatrix() override;

				virtual void SetPosition(const float& x, const float& y, const float& z);
				virtual glm::vec3* GetPosition();
				glm::vec3 position;
			private:
				
				glm::mat4 proj;
				glm::mat4 view;
				glm::mat4 projView;
				glm::mat4 model;
			};
		}
	}
}
