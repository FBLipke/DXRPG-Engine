#pragma once
#include <Platform/Platform.h>

class Layer
{
public:
	Layer(const int& id);

	~Layer();

	void Add_Tile(const glm::vec2 & position);
	void Remove_Tile(const int& id);
private:
	int id;
	std::vector<Tile> tiles;
};
