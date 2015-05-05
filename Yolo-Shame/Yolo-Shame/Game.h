#pragma once

#include<SFML\Graphics.hpp>

#include "Grid.h"
#include "Player.h"

class Game
{
public:
	static sf::RenderWindow& GetWindow() { return mWindow; }
	static Player* GetPlayer(Player::PlayerID id) { return &mPlayers[id]; }

	static void Init();
	static void Deinit();

	static void Run();
private:
	static sf::RenderWindow mWindow;
	static Player mPlayers[Player::NUM_PLAYER];

	static Grid mBoard;
	

	static void HandleEvents();
	static void Update();
	static void Render();
};

