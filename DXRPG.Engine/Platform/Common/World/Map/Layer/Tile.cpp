#include <Platform/Platform.h>

Tile::Tile(const glm::vec2& position)
{
	this->position = position;
}


Tile::~Tile()
{
}

void Tile::Set_Position(glm::vec2& position)
{
	this->position = position;
}
