#pragma once

#include<SFML\Graphics.hpp>

#include "Units.h"

class Tile
{
public:
	Tile();
	~Tile() = default;


	void Init(sf::Vector2f pos, Units units);
	void Deinit();

	void Draw();
private:
	sf::RectangleShape mShape;

	Units mUnit;
};

