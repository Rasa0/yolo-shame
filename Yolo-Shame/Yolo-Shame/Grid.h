#pragma once

#include<string>

#include<SFML\Graphics.hpp>

#include "Tile.h"

class Grid
{
public:
	Grid();
	~Grid();

	void Init(unsigned int width, unsigned int length, sf::Vector2f position = { 30, 30 });
	void Deinit();

	void LoadFromFile(std::string path); // Incomplete: does not load from a file yet


	sf::Vector2f GetPosition() { return mPosition; }
	float GetTileSize() { return mTileSize; }
	Tile* GetTile(sf::Vector2u tileIndex);

	void SetPosition(sf::Vector2f position);
	
	bool GridRectContains(sf::Vector2f position);
	void HandleClick(sf::Vector2u tileIndex, sf::Mouse::Button);
	bool IsAdjacent(Tile* first, Tile* second);

	void SelectTile(Tile* tile);

	void Draw();
private:
	unsigned int mWidth, mHeight;
	sf::FloatRect mGridRect;
	sf::Vector2f mPosition; // Redundant? add in Game only?

	Tile* mSelectedTile;

	const float mTileSize=32;

	Tile** mGrid;
};