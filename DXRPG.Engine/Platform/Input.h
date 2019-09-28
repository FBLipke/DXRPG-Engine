#pragma once
#include <Platform/Platform.h>

class Input
{
public:
	Input();
	void Set_PressedKey(const int & key);
	void Set_ReleasedKey(const int & key);
	int Get_PressedKey();
	bool IsKeyPressed(const int & key);
	virtual ~Input();
private:
	bool keys[1024];
};

