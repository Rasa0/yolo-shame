#pragma once

#include<SFML\Graphics.hpp>

class Player
{
public:
	Player()  = default;
	~Player() = default;

	Player(int id, sf::Color color) : mID(id), mColor(color) {}


	void setColor(sf::Color color) { mColor = color; }
	void setID(int id) { mID = id; }

	sf::Color getColor() { return mColor; }
	int getID() { return mID; }
private:
	int mID;
	sf::Color mColor;
};

