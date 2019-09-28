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

			void Begin_Render();
			bool Render();
			void End_Render();

			auto Get_Window() const -> Window*;

		protected:
			float fps;
			Window* window;
			Renderer::Camera* camera;
			Renderer::Shader* shader = nullptr;
			Renderer::Renderer* renderer = nullptr;
			bool paused;
			void CalculateFPS(float dt);
			void Shutdown() const;
			void _GameLoop();
		};
	}
}
