#pragma once
#include<vector>

#include<SFML\Graphics.hpp>

#include "Grid.h"
#include "Player.h"

class Game
{
public:
	static void Init();
	static void Deinit();

	static sf::RenderWindow& GetWindow() { return mWindow; }
	static Player* GetPlayer(Player::PlayerID id) { return &mPlayers[id]; }
	static sf::Font& GetFont() { return mFont; };

	static void Run();
private:
	static sf::RenderWindow mWindow;
	static sf::Font mFont;

	static Player mPlayers[Player::NUM_PLAYER];
	static Grid mBoard;
	static sf::Vector2f mBoardPos;

	static std::vector<sf::Drawable*> mDrawables;	

	static void HandleEvents();
	static void HandleMousePress(sf::Event);
	static void Update();
	static void Render();
};

