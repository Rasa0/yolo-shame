
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
		if (IsAdjacent(mSelectedTile, tileIndex))
		{
			//std::cout << "Is adjacent!" << std::endl; // DEBUG
			sf::Vector2u other = tileIndex;

			Tile& currentTile = GetTile(mSelectedTile);
			Direction dir = GetDirection(mSelectedTile, other);
			unsigned int amount = currentTile.GetUnitCount()/2;

			currentTile.SetMove(dir, amount);
		} 
		else
		{
			std::cout << "Can't move, not adjacent!" << std::endl; // DEBUG
		}
		break;
	default:
		break;
	}
}

bool Grid::IsAdjacent(sf::Vector2u first, sf::Vector2u second)
{
	int difX = first.x - second.x;
	int difY = first.y - second.y;

	return (difX == 0 && (difY == -1 || difY == 1)) || (difY == 0 && (difX == -1 || difX == 1));
}

Direction Grid::GetDirection(sf::Vector2u from, sf::Vector2u to)
{
	sf::Vector2i dir = sf::Vector2i(to - from);

	if (dir.x == 1 && dir.y == 0)
	{
		cout << "Right" << endl;
		return DirectionRight;
	}
	else if (dir.x == -1 && dir.y == 0)
	{
		cout << "Left" << endl;
		return DirectionLeft;
	}

	if (dir.y == 1 && dir.x == 0)
	{
		cout << "Down" << endl;
		return DirectionDown;
	} 
	else if (dir.y == -1 && dir.x == 0)
	{
		cout << "Up" << endl;
		return DirectionUp;
	}

	return DirectionNone;
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