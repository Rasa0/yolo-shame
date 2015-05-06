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
	//void SetTileSize(float size);


	//void ResetTileSize();
	//void ResetGridRect();

	void Draw();
private:
	int mWidth, mHeight;
	sf::FloatRect mGridRect;
	sf::Vector2f mPosition; // Redundant? add in Game only?

	const float mTileSize=32;

	Tile** mGrid;
};