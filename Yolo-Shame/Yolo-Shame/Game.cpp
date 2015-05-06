
#include<iostream>

#include "Game.h"

sf::RenderWindow Game::mWindow;
Player Game::mPlayers[Player::NUM_PLAYER];
sf::Font Game::mFont;

Grid Game::mBoard;
sf::Vector2f Game::mBoardPos;
float Game::mTileSize;


void Game::Init()
{
	mWindow.create({ 800, 600 }, "Tile Wars");
	mFont.loadFromFile("Media/Fonts/arial.ttf");

	Game::mPlayers[0].Init(Player::PLAYER1, sf::Color::Blue);
	Game::mPlayers[1].Init(Player::PLAYER2, sf::Color::Red);

	mTileSize = 32.f;

	mBoardPos = { 30, 30 };
	mBoard.LoadFromFile("blaj"); // Incomplete

}

void Game::Deinit() {}

void Game::Run()
{
	// Game loop:
	while (mWindow.isOpen())
	{
		HandleEvents();
		Update();
		Render();
	}
}

void Game::HandleEvents()
{
	sf::Event event; // Is a Union, members available depend on EventType
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::EventType::Closed:
				mWindow.close();
				break;
			default:
				break;
		}
	}
}

void Game::Update()
{
}

void Game::Render()
{
	mWindow.clear();

	mBoard.Draw();

	mWindow.display();
}

void Game::SetTileSize(float size)
{
	mTileSize = size;

	mBoard.SetPosition(mBoard.GetPosition());
	mBoard.ResetTileSize();
}