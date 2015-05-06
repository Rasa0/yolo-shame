#pragma once

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
	static float GetTileSize() { return mTileSize; };

	static void SetTileSize(float size);

	static void Run();
private:
	static sf::RenderWindow mWindow;
	static sf::Font mFont;

	static Player mPlayers[Player::NUM_PLAYER];
	static Grid mBoard;
	static sf::Vector2f mBoardPos;
	static float mTileSize; // Redundant? should this be in the grid instead?


	static void HandleEvents();
	static void Update();
	static void Render();
};

