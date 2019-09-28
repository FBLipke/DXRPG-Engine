#pragma once
#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			class __DLLEXPORT Camera
			{
			public:
				Camera() {};
				Camera(Window * w) {};

				virtual ~Camera() = default;
				virtual void Update(Window * w) = 0;
				
				virtual glm::mat4& Get_ProjectionViewMatrix() = 0;

				virtual void SetPosition(const float& x, const float& y, const float& z) = 0;
				virtual glm::vec3* GetPosition() = 0;
			};
		}
	}
}
