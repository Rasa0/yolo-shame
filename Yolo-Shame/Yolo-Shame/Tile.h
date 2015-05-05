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

	void Init(TileType type, Player* owner=nullptr, unsigned int unitCount=0);

	void SetPosition(sf::Vector2f pos);
	void SetType(TileType type);
	void SetOwner(Player* owner);
	void SetUnitCount(unsigned int count);

	void Draw();
private:
	

	sf::RectangleShape mShape;

	TileType mType;
	Player* mOwner;
	unsigned int mUnitCount;
};