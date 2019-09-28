#include <Platform/Platform.h>

Input::Input()
{
	for (int key = 0; key < 1024; key++)
		keys[key] = false;
}

void Input::Set_PressedKey(const int& key)
{
	keys[key] = true;
}

void Input::Set_ReleasedKey(const int& key)
{
	keys[key] = false;
}

int Input::Get_PressedKey()
{
	for (int key = 0; key < sizeof(keys); key++)
		if (IsKeyPressed(key))
			return key;

	return -1;
}

bool Input::IsKeyPressed(const int& key)
{
	return keys[key] == true;
}

Input::~Input()
{
}
