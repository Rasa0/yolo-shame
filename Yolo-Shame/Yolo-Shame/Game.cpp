
#include<iostream>

#include "Game.h"

sf::RenderWindow Game::mWindow;
Player Game::mPlayers[Player::NUM_PLAYER];
sf::Font Game::mFont;

Grid Game::mBoard;
sf::Vector2f Game::mBoardPos;


void Game::Init()
{
	mWindow.create({ 800, 600 }, "Tile Wars");
	mFont.loadFromFile("Media/Fonts/arial.ttf");

	Game::mPlayers[0].Init(Player::PLAYER1, sf::Color::Blue);
	Game::mPlayers[1].Init(Player::PLAYER2, sf::Color::Red);

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
		case sf::Event::EventType::MouseButtonPressed:
			HandleMousePress(event);
			break;
		case sf::Event::EventType::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
}

void Game::HandleMousePress(sf::Event event)
{
	// TODO: Refactor this to mBoard? (make a handleclick function in mGrid)
	sf::Vector2f clickedCoords = mWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }); // TODO: Can this get negative?

	if (mBoard.GridRectContains(clickedCoords))
	{
		sf::Vector2u tileIndex = sf::Vector2u{ clickedCoords / mBoard.GetTileSize() };
		tileIndex.x -= 1;
		tileIndex.y -= 1;

		mBoard.HandleClick(tileIndex, event.mouseButton.button);
	}

	switch (event.mouseButton.button)
	{
	case sf::Mouse::Left:
		break;
	case sf::Mouse::Right:
		break;
	default:
		break;
	}
}

void Game::Update()
{
}

void Game::Render()
{
	mWindow.clear(sf::Color::Magenta);

	mBoard.Draw();

	mWindow.display();
}
