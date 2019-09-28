#pragma once
#include <Platform/Platform.h>

class World
{
public:
	World();
	virtual ~World();

	void Generate();
private:
	std::vector<Map> maps;
};

