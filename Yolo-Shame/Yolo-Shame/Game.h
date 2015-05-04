#pragma once

#include<SFML\Graphics.hpp>

#include "Grid.h"

class Game
{
public:
	Game();
	~Game() = default;


	static sf::RenderWindow& getWindow() { return mWindow; }

	void Run();
private:
	static sf::RenderWindow mWindow;

	Grid mBoard;

	void HandleEvents();
	void Update();
	void Render();
};

