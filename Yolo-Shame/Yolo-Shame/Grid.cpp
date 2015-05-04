
#include "Game.h"
#include "Grid.h"
#include "Player.h"
#include "Units.h"

Grid::Grid()
{
	mGrid = nullptr;
}

void Grid::Deinit()
{
	if (mGrid == nullptr)
		return;

	for (int i = 0; i < mWidth; i++)
	{
		delete mGrid[i];
	}

	delete mGrid;

	mGrid = nullptr;
}

void Grid::Init(int width, int height)
{
	mWidth = width;
	mHeight = height;

	mGrid = new Tile*[width];

	for (int i = 0; i < width; i++)
	{
		mGrid[i] = new Tile[height];
	}

	Player tPlayer(0, sf::Color::White);
	Units tUnits(tPlayer, 0);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			mGrid[i][j].Init({ i * 32.f, j * 32.f }, tUnits);
		}
	}
}

void Grid::Draw()
{
	for (int i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mGrid[i][j].Draw();
		}
	}
}