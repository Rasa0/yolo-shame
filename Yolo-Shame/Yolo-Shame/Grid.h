#pragma once

#include<string>

#include<SFML\Graphics.hpp>

#include "Tile.h"

class Grid
{
public:
	Grid();
	~Grid();


	void Init(int width, int length);
	void Deinit();

	void LoadFromFile(std::string path);

	void Draw();
private:
	int mWidth, mHeight;

	Tile** mGrid;
};