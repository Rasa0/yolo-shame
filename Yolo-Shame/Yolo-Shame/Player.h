#pragma once

#include<SFML\Graphics.hpp>

class Player
{
public:
	enum PlayerID
	{
		NoPlayer = 0,
		Player1,
		Player2
	};

	Player() : mColor(sf::Color::White), mID(NoPlayer) {}
	~Player() = default;

	Player(PlayerID id, sf::Color color) : mID(id), mColor(color) {}


	void setColor(sf::Color color) { mColor = color; }
	void setID(PlayerID id) { mID = id; }

	sf::Color getColor() { return mColor; }
	PlayerID getID() { return mID; }
private:
	PlayerID mID;
	sf::Color mColor;
};

