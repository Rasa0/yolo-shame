#include "Direction.h"

#include<SFML\Graphics.hpp>

Direction GetDirection(sf::Vector2u from, sf::Vector2u to)
{
	sf::Vector2i dir = sf::Vector2i(to - from);

	if (dir.x == 1 && dir.y == 0)
	{
		return DirectionRight;
	}
	else if (dir.x == -1 && dir.y == 0)
	{
		return DirectionLeft;
	}

	if (dir.y == 1 && dir.x == 0)
	{
		return DirectionDown;
	}
	else if (dir.y == -1 && dir.x == 0)
	{
		return DirectionUp;
	}

	return DirectionNone;
}