#pragma once

#include<SFML\Graphics.hpp>

class Player
{
public:
	enum PlayerID
	{
		PLAYER1=0,
		PLAYER2,
		NUM_PLAYER
	};

	Player() : mColor(sf::Color::White) {}

	Player(PlayerID id, sf::Color color) : mID(id), mColor(color) {}


	void Init(PlayerID id, sf::Color color);

	void setColor(sf::Color color) { mColor = color; }
	void setID(PlayerID id) { mID = id; }

	sf::Color getColor() { return mColor; }
	PlayerID getID() { return mID; }
private:
	PlayerID mID;
	sf::Color mColor;
};

