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

<<<<<<< HEAD
				virtual void SetPosition(const float& x, const float& y, const float& z);
				virtual glm::vec3* GetPosition();
=======
				void SetPosition(const float& x, const float& y, const float& z) override;
			private:
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc
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
