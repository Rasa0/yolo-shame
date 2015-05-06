
#include<fstream>

#include "Game.h"
#include "Grid.h"
#include "Tile.h"
#include "Player.h"

Grid::Grid() : mGrid(nullptr), mPosition({ 0, 0 }) {}

Grid::~Grid() { Deinit(); }


void Grid::Init(int width, int height, sf::Vector2f position)
{
	Deinit();

	mWidth = width;
	mHeight = height;

	mPixelWidth = width*Game::GetTileSize();
	mPixelHeight = height*Game::GetTileSize();

	mGrid = new Tile*[width];

	for (int i = 0; i < width; i++)
	{
		mGrid[i] = new Tile[height];
	}

	SetPosition(position);
}

void Grid::Deinit()
{
	if (mGrid == nullptr)
		return;

	for (int i = 0; i < mWidth; i++)
	{
		delete[] mGrid[i];
	}

	delete[] mGrid;

	mGrid = nullptr;
}

void Grid::LoadFromFile(std::string path) // Incomplete
{
	Init(10, 10); // MagicNumber: grid size, get this from file later

	for (int i = 0; i < mWidth; i++)
	{
		mGrid[i][0].Init(Tile::Wall);
		mGrid[i][mHeight - 1].Init(Tile::Wall);
	}
	for (int i = 0; i < mHeight; i++)
	{
		mGrid[0][i].Init(Tile::Wall);
		mGrid[mWidth - 1][i].Init(Tile::Wall);
	}

	mGrid[1][1].Init(Tile::Walkable, Game::GetPlayer(Player::PLAYER1), 100);
	mGrid[mWidth - 2][mHeight - 2].Init(Tile::Walkable, Game::GetPlayer(Player::PLAYER2), 100);
}

void Grid::SetPosition(sf::Vector2f position)
{
	mPosition = position;

	for (int i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mGrid[i][j].SetPosition(sf::Vector2f{ i * Game::GetTileSize(), j * Game::GetTileSize() } + mPosition); // Offset the tile pos with grid pos
		}
	}
}

void Grid::ResetTileSize()
{
	for (int i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mGrid[i][j].SetSize();
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