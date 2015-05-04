#include<iostream>

#include "Game.h"

using namespace std; // bleh

Game::Game()
{
	mWindow.create({ 800, 600 }, "Title Text");

	mShape.setFillColor(sf::Color::Green);
	mShape.setPosition({ 100, 100 });
	mShape.setRadius(50);
}

void Game::run()
{
	// Game loop:
	while (mWindow.isOpen())
	{
		handleEvents();
		update(); // TODO: Fix dt and proper time handling
		render();
	}
}

void Game::handleEvents()
{
	sf::Event event; // Is a Union, members available depend on EventType
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::EventType::Closed:
				mWindow.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{
					mWindow.setTitle("SPAAAAACE!");
				}
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();

	mWindow.draw(mShape);

	mWindow.display();
}