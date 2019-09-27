#include <Platform/Platform.h>

namespace DXRPG
{
	namespace Engine
	{
		namespace Renderer
		{
			OrthographicCamera::OrthographicCamera(Window * w)
			{
				this->position = glm::vec3(0.0f, 0.0f, 0.0f);
				this->view = glm::mat4(1.0f);

				this->proj = glm::ortho(1.0f, w->Get_FrameBufferWidth(),
					w->Get_FrameBufferHeight(), 1.0f, -1.0f, 10.0f);

				projView = proj * view;
			}

			OrthographicCamera::~OrthographicCamera()
			{
			}

			/*
				X = left & Right
				Y = Up & Down
				Z = zoom
			*/
			void OrthographicCamera::SetPosition(const float& x, const float& y, const float& z)
			{
				this->position.x = x;
				this->position.y = y;
				this->position.z = z;
			}

			void OrthographicCamera::Update(Window * w)
			{
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
					glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1, 0, 0));

				view = glm::inverse(transform);

				projView = proj * view;
			}

			glm::mat4& OrthographicCamera::Get_ProjectionViewMatrix()
			{
				return this->projView;
			}
		}
	}
}
