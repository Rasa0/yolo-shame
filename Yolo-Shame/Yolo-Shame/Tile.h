#pragma once

#include<SFML\Graphics.hpp>

#include "Player.h"
#include "Game.h"
#include "Direction.h"

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

	void Init(TileType type, Player* owner = nullptr, unsigned int unitCount = 0);

	void SetSize(float size);
	void SetPosition(sf::Vector2f pos);
	void SetType(TileType type);
	void SetOwner(Player* owner);
	void SetUnitCount(unsigned int count);
	void SetSelected(bool selected);
	void SetMove(Direction direction, unsigned int amount);

	unsigned int GetUnitCount() { return mUnitCount; }

	void Draw();
private:
	sf::RectangleShape mBackground; // HACK? perhaps make a TileShape that inherits drawable
	sf::RectangleShape mOutline;
	sf::RectangleShape mSelectOutline;

	TileType mType;
	Player* mOwner;

	unsigned int mUnitCount;
	Direction mMoveDirection;
	unsigned int mMoveAmount;


	bool mSelected;
};