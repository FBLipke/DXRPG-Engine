#pragma once
#include <Platform/Platform.h>

class Tile
{
public:
	Tile() = default;
	explicit Tile(const glm::vec2& position);
	virtual ~Tile();

	void Set_Position(glm::vec2& position);
private:
	glm::vec2 position{};
};

