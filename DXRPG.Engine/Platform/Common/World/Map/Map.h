#pragma once
#include <Platform/Platform.h>

class Map
{
	
public:
	explicit Map(const glm::vec3& mapSize);
	~Map();
	void Add_Layer(const int & layerId, const glm::vec3 & size);
	void Generate();

private:
	std::vector<Layer> map_layers;
	glm::vec3 mapSize;
};

