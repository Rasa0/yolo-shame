
#include<iostream>
#include<fstream>

#include "Game.h"
#include "Grid.h"
#include "Tile.h"
#include "Player.h"

#include "Direction.h"

Grid::Grid() : mGrid(nullptr)
{
	SetPosition({ 0, 0 });
}

Grid::~Grid() { Deinit(); }


void Grid::Init(unsigned int width, unsigned int height, sf::Vector2f position)
{
	Deinit();

	mGrid = new Tile*[width];

	for (unsigned int i = 0; i < width; i++)
	{
		mGrid[i] = new Tile[height];
		
		for (unsigned int j = 0; j < height; j++)
		{
			mGrid[i][j].Init({ i, j });
		}
	}

	mWidth = width;
	mHeight = height;

	mGridRect.width = width*GetTileSize();
	mGridRect.height = height*GetTileSize();

	SetPosition(position);

	//SelectTile(nullptr);
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
		mGrid[i][0].SetType(Tile::Wall);
		mGrid[i][mHeight - 1].SetType(Tile::Wall);
	}
	for (unsigned int i = 0; i < mHeight; i++)
	{
		mGrid[0][i].SetType(Tile::Wall);
		mGrid[mWidth - 1][i].SetType(Tile::Wall);
	}

	Tile* player1Spawn = GetTile({ 1, 1 });
	player1Spawn->SetOwner(Game::GetPlayer(Player::PLAYER1));
	player1Spawn->SetUnitCount(100);

	Tile* player2Spawn = GetTile({ mWidth - 2, mHeight - 2 });
	player2Spawn->SetOwner(Game::GetPlayer(Player::PLAYER2));
	player2Spawn->SetUnitCount(100);

	SelectTile(nullptr);
}

Tile* Grid::GetTile(sf::Vector2u tileIndex)
{
	if (tileIndex.x > mWidth || tileIndex.y > mHeight)
	{
		return nullptr;
	}
	else
	{
		return &mGrid[tileIndex.x][tileIndex.y];
	}
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
	Tile* clickedTile = GetTile(tileIndex);

	if (clickedTile == nullptr) 
	{ 
		std::cout << "HandleClick tileIndex is not valid index! something is wrong!" << std::endl;
		return;
	}

	switch (button)
	{
	case sf::Mouse::Left:
		SelectTile(clickedTile);
		break;
	case sf::Mouse::Right:
		if (IsAdjacent(mSelectedTile, clickedTile))
		{
			std::cout << "Is adjacent!" << std::endl; // DEBUG

			Direction dir = GetDirection(mSelectedTile->GetGridIndex(), tileIndex);
			unsigned int amount = mSelectedTile->GetUnitCount()/2;

			mSelectedTile->SetMove(dir, amount);
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

bool Grid::IsAdjacent(Tile* first, Tile* second)
{
	sf::Vector2u firstIndex  = first->GetGridIndex();
	sf::Vector2u secondIndex = second->GetGridIndex();

	int difX = firstIndex.x - secondIndex.x;
	int difY = firstIndex.y - secondIndex.y;

	return (difX == 0 && (difY == -1 || difY == 1)) || (difY == 0 && (difX == -1 || difX == 1));
}

void Grid::SelectTile(Tile* tile)
{
	if (mSelectedTile != nullptr)
	{
		mSelectedTile->SetSelected(false);
	}

	mSelectedTile = tile;

	if (tile != nullptr)
	{
		tile->SetSelected(true);
	}
}

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