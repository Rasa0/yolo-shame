#pragma once

#include<SFML\Graphics.hpp>

#include "Player.h"

class Tile
{
public:
	enum TileType
	{
		Wall = 0,
		Walkable
	};

	Tile();
	~Tile() = default;

	void setPosition(sf::Vector2f pos) {mShape.setPosition(pos);}

	void Draw();
private:
	

	sf::RectangleShape mShape;

	TileType mType;
	Player mOwner;
	unsigned int mUnitCount;
};