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

	void SetPosition(sf::Vector2f);

	void ResetTileSize();

	void Draw();
private:
	int mWidth, mHeight;
	float mPixelWidth, mPixelHeight;

	sf::Vector2f mPosition; // Redundant? add in Game only?

	Tile** mGrid;
};