#include "Platform.h"

bool DXRPG::Engine::OutErrorMsg(const char* message)
{
	MessageBox(NULL, message, "Engine Error", MB_ICONEXCLAMATION);
	return false;
}
