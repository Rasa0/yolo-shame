
#include "Game.h"
#include "Tile.h"

Tile::Tile()
: mType(Walkable), mUnitCount(0), mOwner(nullptr)
{
	mShape.setSize({ 32, 32 });
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
		case Tile::Walkable:  // FLAG?
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


void Tile::Draw()
{
	Game::GetWindow().draw(mShape);

	if (mOwner)
	{
		sf::CircleShape playerToken({ 16 }); // TODO: put all these semi-temp vars somewhere good
		playerToken.setFillColor(mOwner->getColor());
		playerToken.setPosition(mShape.getPosition());

		sf::Text unitcount({ std::to_string(mUnitCount) }, Game::GetFont(), 12u);
		unitcount.setPosition(mShape.getPosition() + sf::Vector2f{4, 8}); // TODO: make sure text is rendered in the middle without magic numbers

		Game::GetWindow().draw(playerToken);
		Game::GetWindow().draw(unitcount);
	}
}