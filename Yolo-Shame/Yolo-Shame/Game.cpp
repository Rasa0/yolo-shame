
#include "Game.h"

sf::RenderWindow Game::mWindow;

Game::Game()
{
	mWindow.create({ 800, 600 }, "Tile Wars");

	mBoard.Init(15, 15);
}

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