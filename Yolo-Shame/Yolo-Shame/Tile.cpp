
#include "Game.h"
#include "Tile.h"

Tile::Tile()
: mType(Walkable), mUnitCount(0), mOwner(nullptr)
{
	mShape.setSize({ 32, 32 }); // TODO: chhage?
	mShape.setFillColor(sf::Color::White);

	mShape.setOutlineColor(sf::Color::Black);
	mShape.setOutlineThickness(1.f);
}

void Tile::Init(TileType type, Player* owner, unsigned int unitCount)
{
	SetType(type);
	SetOwner(owner);
	SetUnitCount(unitCount);
}


void Tile::SetPosition(sf::Vector2f pos)
{
	mShape.setPosition(pos);
}

void Tile::SetType(TileType type)
{
	mType = type;

	switch (type)
	{
		case Tile::Wall:
			mShape.setFillColor({ 75, 75, 75, 255 });
			break;
		case Tile::Walkable:  // Change? flag?
			mShape.setFillColor(sf::Color::White);
			break;
		default:
			break;
	}
}

void Tile::SetUnitCount(unsigned int count)
{
	mUnitCount = count;
}

void Tile::SetOwner(Player* owner)
{
	mOwner = owner;
}

void Tile::SetSize(float size)
{
	mShape.setSize({ size, size });
}

void Tile::Draw()
{
	Game::GetWindow().draw(mShape);

	if (mOwner)
	{
		sf::CircleShape playerToken(mShape.getSize().x/2.f); // TODO: put all these semi-temp vars somewhere good
		playerToken.setFillColor(mOwner->getColor());
		playerToken.setPosition(mShape.getPosition());

		sf::Text unitcount({ std::to_string(mUnitCount) }, Game::GetFont(), 12u*mShape.getSize().x/32u); // MagicNumber: sizes, the ratio is just for rezizing
		unitcount.setPosition(mShape.getPosition() + sf::Vector2f{ 5 * mShape.getSize().x / 32u, 8 * mShape.getSize().x / 32u }); // MagicNumber: text position and sizes

		Game::GetWindow().draw(playerToken);
		Game::GetWindow().draw(unitcount);
	}
}