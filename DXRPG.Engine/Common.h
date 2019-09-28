#pragma once
#include "Platform\Platform.h"

namespace DXRPG
{
	namespace Engine
	{
		class __DLLEXPORT Common final
		{
		public:
			Common();

			explicit Common(HINSTANCE hInstance);
			~Common();

			bool Inititalize();
			bool Start();
			bool Event();
			bool Update(float dt) const;

<<<<<<< HEAD
			Window* Get_Window() const;
			Input* Get_Input();
=======
			void Begin_Render();
			bool Render();
			void End_Render();

			auto Get_Window() const -> Window*;
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc

			DXRPG::Engine::Renderer::OrthographicCamera* Get_Camera();
		protected:
			float fps;
			Window* window;
<<<<<<< HEAD
			Input* input;
			DXRPG::Engine::Renderer::OrthographicCamera* camera;
			DXRPG::Engine::Renderer::Shader* shader = nullptr;
			DXRPG::Engine::Renderer::Renderer* renderer = nullptr;
		protected:
=======
			Renderer::Camera* camera;
			Renderer::Shader* shader = nullptr;
			Renderer::Renderer* renderer = nullptr;
>>>>>>> b29d8ef3ed95859e24539b60c248b8afab8981cc
			bool paused;
			void CalculateFPS(float dt);
			void Shutdown() const;
			void _GameLoop();
		};
	}
}
