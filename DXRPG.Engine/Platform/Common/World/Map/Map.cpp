#include <Platform/Platform.h>

Map::Map(const glm::vec3& mapSize)
{
	this->mapSize = mapSize;
}

Map::~Map()
= default;

void Map::Add_Layer(const int& layerId, const glm::vec3& size)
{
	this->map_layers.emplace_back(layerId);

	for (auto iY = 0; iY < size.y; iY++)
	{
		for (auto iX = 0; iX < size.x; iX++)
		{
			this->map_layers.at(layerId).Add_Tile
				(glm::vec2(iX * 32, iY * 32));
		}
	}
}

void Map::Generate()
{
	this->mapSize = glm::vec3(80, 80, 16);
	
	for (auto iL = 0; iL < this->mapSize.z; iL++)
		Add_Layer(iL, this->mapSize);
}
