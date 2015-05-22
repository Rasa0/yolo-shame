#pragma once

#include<SFML\Graphics.hpp>

enum Direction
{
	DirectionNone = 0,
	DirectionUp,
	DirectionLeft,
	DirectionDown,
	DirectionRight
};

Direction GetDirection(sf::Vector2u from, sf::Vector2u to);