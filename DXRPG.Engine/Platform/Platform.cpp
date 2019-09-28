#include "Platform.h"

bool DXRPG::Engine::OutErrorMsg(const char* message)
{
	MessageBox(nullptr, message, "Engine Error", MB_ICONEXCLAMATION);
	return false;
}
