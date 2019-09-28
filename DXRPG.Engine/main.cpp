#include <Common.h>

namespace DXRPG
{
	int DXRPG_main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
	{
		{
			auto engine = new Engine::Common(hInstance);

			if (engine->Inititalize())
				engine->Start();

			delete engine;
		}
		return 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return DXRPG::DXRPG_main(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}
