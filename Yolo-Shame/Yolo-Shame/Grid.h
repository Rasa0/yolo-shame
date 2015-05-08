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

	void SetPosition(sf::Vector2f position);
	
	bool GridRectContains(sf::Vector2f position);

	void SelectTile(sf::Vector2u tile);

	void Draw();
private:
	unsigned int mWidth, mHeight;
	sf::FloatRect mGridRect;
	sf::Vector2f mPosition; // Redundant? add in Game only?

	sf::Vector2u mSelectedTile;

	const float mTileSize=32;

	Tile** mGrid;
};