
#include "Grid.h"

Grid::Grid() { mGrid = nullptr; }

Grid::~Grid() { Deinit(); }


void Grid::Init(int width, int height)
{
	Deinit();

	mWidth = width;
	mHeight = height;

	mGrid = new Tile*[width];

	for (int i = 0; i < width; i++)
	{
		mGrid[i] = new Tile[height];

		for (int j = 0; j < height; j++)
		{
			mGrid[i][j].setPosition({ i * 32.f, j * 32.f });
		}
	}
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