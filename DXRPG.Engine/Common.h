#pragma once
#include "Platform\Platform.h"

namespace DXRPG
{
	namespace Engine
	{
		class __DLLEXPORT Common
		{
		public:
			Common() {};
			
			Common(HINSTANCE hInstance);
			virtual ~Common();

			virtual bool Inititalize();
			virtual bool Start();
			virtual bool Event();
			virtual bool Update(float dt);

			virtual void Begin_Render();
			virtual bool Render();
			virtual void End_Render();

			Window* Get_Window() const;

		protected:
			float fps;
			Window* window;
			DXRPG::Engine::Renderer::Camera* camera;
			DXRPG::Engine::Renderer::Shader* shader = nullptr;
			DXRPG::Engine::Renderer::Renderer* renderer = nullptr;
		protected:
			bool paused;
			void CalculateFPS(float dt);
			void Shutdown();
			void _GameLoop();
		};
	}
}