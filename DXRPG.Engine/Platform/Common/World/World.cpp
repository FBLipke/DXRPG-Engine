#include "World.h"

World::World()
= default;


World::~World()
= default;

void World::Generate()
{
	glm::vec3 size = glm::vec3(80, 80, 16);
	this->maps.emplace_back(size);

	for (auto& map : this->maps)
	{
		map.Generate();
	}
}
