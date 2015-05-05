
#include "Game.h"

sf::RenderWindow Game::mWindow;
Player Game::mPlayers[Player::NUM_PLAYER];
Grid Game::mBoard;


void Game::Init()
{
	mWindow.create({ 800, 600 }, "Tile Wars");

	mBoard.LoadFromFile("blaj");

	Game::mPlayers[0].Init(Player::PLAYER1, sf::Color::Blue);
	Game::mPlayers[1].Init(Player::PLAYER2, sf::Color::Red);
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