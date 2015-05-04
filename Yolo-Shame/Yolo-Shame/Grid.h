#pragma once

#include<SFML\Graphics.hpp>

#include "Tile.h"

class Grid
{
public:
	Grid();
	~Grid() = default;


	void Init(int width, int length);
	void Deinit();

	void Draw();
private:
	int mWidth, mHeight;

	Tile** mGrid;
};