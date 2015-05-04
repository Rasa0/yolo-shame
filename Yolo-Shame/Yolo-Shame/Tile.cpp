
#include "Game.h"
#include "Tile.h"

Tile::Tile()
: mType(Walkable), mUnitCount(0)
{
	mShape.setSize({ 32, 32 });
	mShape.setFillColor(sf::Color::White);

	mShape.setOutlineColor(sf::Color::Black);
	mShape.setOutlineThickness(1.f);
}

void Tile::Draw()
{
	Game::getWindow().draw(mShape);
}