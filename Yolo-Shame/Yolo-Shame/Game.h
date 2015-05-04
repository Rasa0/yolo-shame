#pragma once // GCC supports this, so it should works on Linux?

#include<SFML\Graphics.hpp>
class Game
{
public:
	Game();
	~Game()=default;

	void run();
private:
	sf::RenderWindow mWindow;

	sf::CircleShape mShape;

	void handleEvents();
	void update();
	void render();
};

