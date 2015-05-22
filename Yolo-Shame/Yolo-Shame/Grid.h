#pragma once

#include<string>

#include<SFML\Graphics.hpp>

#include "Tile.h"

class Grid
{
public:
	Grid();
	~Grid();


	void Init(int width, int length, sf::Vector2f position = { 30, 30 });
	void Deinit();

	void LoadFromFile(std::string path); // Incomplete

	sf::Vector2f GetPosition() { return mPosition; }
	float GetTileSize() { return mTileSize; }
	Tile& GetTile(sf::Vector2u tileIndex) { return mGrid[tileIndex.x][tileIndex.y]; }

	void SetPosition(sf::Vector2f position);
	
	bool GridRectContains(sf::Vector2f position);
	void HandleClick(sf::Vector2u tileIndex, sf::Mouse::Button);
	bool IsAdjacent(sf::Vector2u first, sf::Vector2u second);

	Direction GetDirection(sf::Vector2u from, sf::Vector2u to);

	void SelectTile(sf::Vector2u tileIndex);

	void Draw();
private:
	unsigned int mWidth, mHeight;
	sf::FloatRect mGridRect;
	sf::Vector2f mPosition; // Redundant? add in Game only?

	sf::Vector2u mSelectedTile;

	const float mTileSize=32;

	Tile** mGrid;
};