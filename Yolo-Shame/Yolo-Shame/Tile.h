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
		Empty=0,
		Wall,
		Walkable
	};

	Tile();
	~Tile() = default;

	void Init(sf::Vector2u gridIndex, TileType type = Walkable, Player* owner = nullptr, unsigned int unitCount = 0);

	void SetSize(float size);
	void SetPosition(sf::Vector2f pos);
	void SetType(TileType type);
	void SetOwner(Player* owner);
	void SetUnitCount(unsigned int count);
	void SetSelected(bool selected);
	void SetMove(Direction direction, unsigned int amount);
	void SetGridIndex(sf::Vector2u index) { mGridIndex = index; }

	unsigned int GetUnitCount() { return mUnitCount; }
	sf::Vector2u GetGridIndex() { return mGridIndex; }

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

	sf::Vector2u mGridIndex;

	bool mSelected;
};