
#include<iostream>

#include "Game.h"

sf::RenderWindow Game::mWindow;
Player Game::mPlayers[Player::NUM_PLAYER];
sf::Font Game::mFont;

Grid Game::mBoard;

std::vector<sf::Drawable*> Game::mDrawables;

sf::RectangleShape Game::mTurnButton;
sf::Text Game::mTurnText;
std::string Game::mCurrentTurn[3] = { "Player 1", "Player 2", "Execute" };
int Game::mTurnIndex = 0;

void Game::Init()
{
	mWindow.create({ 800, 600 }, "Tile Wars");
	mFont.loadFromFile("Media/Fonts/arial.ttf");

	Game::mPlayers[0].Init(Player::PLAYER1, sf::Color::Blue);
	Game::mPlayers[1].Init(Player::PLAYER2, sf::Color::Red);

	mBoard.LoadFromFile("blaj"); // Incomplete
	mBoard.SetPosition({ 32, 32 });

	mTurnButton.setPosition({ 400, 50 });
	mTurnButton.setSize({ 80, 20 });

	mTurnText.setFont(mFont);
	mTurnText.setPosition({ 400, 100 });
	mTurnText.setString("BLAJ");
	mTurnText.setColor(sf::Color::White);

	mDrawables.push_back(&mTurnButton);
	mDrawables.push_back(&mTurnText);
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
	sf::Vector2f clickedCoords = mWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }); // TODO: Can the coords get negative?

	if (mBoard.GridRectContains(clickedCoords))
	{
		sf::Vector2u tileIndex = sf::Vector2u{ (clickedCoords - mBoard.GetPosition()) / mBoard.GetTileSize() };
		//tileIndex.x -= 1;
		//tileIndex.y -= 1;

		mBoard.HandleClick(tileIndex, event.mouseButton.button);
	}

	switch (event.mouseButton.button)
	{
	case sf::Mouse::Left:
		if (mTurnButton.getGlobalBounds().contains(clickedCoords))
		{
			AdvanceTurn();
		}
		break;
	case sf::Mouse::Right:
		break;
	default:
		break;
	}
}

void Game::Update()
{
	mTurnText.setString(mCurrentTurn[mTurnIndex]);
}

void Game::Render()
{
	mWindow.clear(sf::Color::Magenta);

	for each(sf::Drawable* drawable in mDrawables)
	{
		mWindow.draw(*drawable);
	}

	mBoard.Draw();

	mWindow.display();
}

void Game::AdvanceTurn()
{
	mTurnIndex = ++mTurnIndex % 3;

	// TODO: Implement tile cleanup
}