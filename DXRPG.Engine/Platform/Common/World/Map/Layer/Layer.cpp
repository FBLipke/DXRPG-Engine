#include <Platform/Platform.h>


Layer::Layer(const int & id)
{
	this->id = id;
}

Layer::~Layer()
= default;

void Layer::Add_Tile(const glm::vec2 & position)
{
	this->tiles.emplace_back(position);
}


void Layer::Remove_Tile(const int& id)
{
}
