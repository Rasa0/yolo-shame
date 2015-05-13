
#include<iostream>
#include<fstream>

#include "Game.h"
#include "Grid.h"
#include "Tile.h"
#include "Player.h"

using namespace std;

Grid::Grid() : mGrid(nullptr)
{
	SetPosition({ 0, 0 });
}

Grid::~Grid() { Deinit(); }


void Grid::Init(int width, int height, sf::Vector2f position)
{
	Deinit();

	mGrid = new Tile*[width];

	for (int i = 0; i < width; i++)
	{
		mGrid[i] = new Tile[height];
	}

	mWidth = width;
	mHeight = height;

	mGridRect.width = width*GetTileSize();
	mGridRect.height = height*GetTileSize();

	SetPosition(position);

	SelectTile({ 0, 0 });
}

void Grid::Deinit()
{
	if (mGrid == nullptr)
		return;

	for (unsigned int i = 0; i < mWidth; i++)
	{
		delete[] mGrid[i];
	}

	delete[] mGrid;

	mGrid = nullptr;
}

void Grid::LoadFromFile(std::string path) // Incomplete
{
	Init(10, 10); // MagicNumber: grid size, get this from file later

	for (unsigned int i = 0; i < mWidth; i++)
	{
		mGrid[i][0].Init(Tile::Wall);
		mGrid[i][mHeight - 1].Init(Tile::Wall);
	}
	for (unsigned int i = 0; i < mHeight; i++)
	{
		mGrid[0][i].Init(Tile::Wall);
		mGrid[mWidth - 1][i].Init(Tile::Wall);
	}

	mGrid[1][1].Init(Tile::Walkable, Game::GetPlayer(Player::PLAYER1), 100);
	mGrid[mWidth - 2][mHeight - 2].Init(Tile::Walkable, Game::GetPlayer(Player::PLAYER2), 100);

	SelectTile({ 0, 0 });
}

void Grid::SetPosition(sf::Vector2f position)
{
	mPosition = position;
	mGridRect.left = position.x;
	mGridRect.top = position.y;

	for (unsigned int i = 0; i < mWidth; i++)
	{
		for (unsigned int j = 0; j < mHeight; j++)
		{
			mGrid[i][j].SetPosition(sf::Vector2f{ i * mTileSize, j * mTileSize } +mPosition); // Offset the tile pos with grid pos
		}
	}
}

bool Grid::GridRectContains(sf::Vector2f position)
{
	return mGridRect.contains(position);
}

void Grid::HandleClick(sf::Vector2u tileIndex, sf::Mouse::Button button)
{
	switch (button)
	{
	case sf::Mouse::Left:
		SelectTile(tileIndex);
		break;
	case sf::Mouse::Right:
		if (IsAdjacent(tileIndex, mSelectedTile))
		{
			// TODO: implement rightclick behaviour
		}
		break;
	default:
		break;
	}
}

bool Grid::IsAdjacent(sf::Vector2u first, sf::Vector2u second)
{
	return ((first.x + 1) == second.x || (first.x - 1) == second.x) != ((first.y + 1) == second.y || (first.y - 1) == second.y);
}

void Grid::SelectTile(sf::Vector2u tileIndex)
{
	if (tileIndex.x > mWidth || tileIndex.y > mHeight)
	{
		// TODO: Handle error
		cout << "Select out of bounds, doing nothing (DEFINE THIS ERROR LATER)";
	} else
	{
		mGrid[mSelectedTile.x][mSelectedTile.y].SetSelected(false);

		mGrid[tileIndex.x][tileIndex.y].SetSelected(true);
		mSelectedTile = tileIndex;
	}
}

/*void Grid::SetTileSize(float size)
{
for (int i = 0; i < mWidth; i++)
{
for (int j = 0; j < mHeight; j++)
{
mGrid[i][j].SetSize(size);
}
}

//SetPosition(mPosition);
}*/

void Grid::Draw()
{
	for (unsigned int i = 0; i < mWidth; i++)
	{
		for (unsigned int j = 0; j < mHeight; j++)
		{
			mGrid[i][j].Draw();
		}
	}
}