#pragma once

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT Camera
			{
			public:
<<<<<<< HEAD
				Camera() {};
				Camera(Window * w) {};
=======
				Camera();
				explicit Camera(Window * w);
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

				virtual ~Camera() = default;
				virtual void Update(Window * w) = 0;
				
				virtual glm::mat4& Get_ProjectionViewMatrix() = 0;

				virtual void SetPosition(const float& x, const float& y, const float& z) = 0;
				virtual glm::vec3* GetPosition() = 0;
			};

			inline Camera::Camera()
			{
			}
		}
	}
}
