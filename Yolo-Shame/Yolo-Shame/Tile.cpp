
#include "Game.h"
#include "Tile.h"

Tile::Tile()
{
	mShape.setSize({ 32, 32 });
	mShape.setFillColor(sf::Color::White);

	mShape.setOutlineColor(sf::Color::Black);
	mShape.setOutlineThickness(1.f);
}

void Tile::Init(sf::Vector2f pos, Units units)
{
	mShape.setPosition(pos);
	mShape.setFillColor(units.getOwner().getColor());
}

void Tile::Deinit() {}

void Tile::Draw()
{
	Game::getWindow().draw(mShape);
}