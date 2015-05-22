
#include <iostream>

#include "Game.h"
#include "Tile.h"

Tile::Tile()
: mType(Walkable), mUnitCount(0), mOwner(nullptr), mSelected(false)
{
	SetSize(32); // MagicNumber: size
	mBackground.setFillColor(sf::Color::White);

	mOutline.setFillColor(sf::Color::Transparent);
	mOutline.setOutlineColor(sf::Color::Black);
	mOutline.setOutlineThickness(1);

	mSelectOutline.setFillColor(sf::Color::Transparent);
	mSelectOutline.setOutlineColor(sf::Color::Blue);
	mSelectOutline.setOutlineThickness(2);
}

void Tile::Init(sf::Vector2u gridIndex, TileType type, Player* owner, unsigned int unitCount)
{
	SetGridIndex(gridIndex);
	SetType(type);
	SetOwner(owner);
	SetUnitCount(unitCount);
	SetSelected(false);
}

void Tile::SetSize(float size)
{
	mBackground.setSize({ size, size });
	mOutline.setSize({ size-2, size-2 });
	mSelectOutline.setSize({ size-4, size-4 });
}

void Tile::SetPosition(sf::Vector2f pos)
{
	mBackground.setPosition(pos);
	mOutline.setPosition({ pos.x + 1, pos.y + 1 });
	mSelectOutline.setPosition({ pos.x + 2, pos.y + 2 });
}

void Tile::SetType(TileType type)
{
	mType = type;

	switch (type)
	{
		case Tile::Wall:
			mBackground.setFillColor({ 75, 75, 75, 255 });
			break;
		case Tile::Walkable:  // Change? flag?
			mBackground.setFillColor(sf::Color::White);
			break;
		default:
			break;
	}
}

void Tile::SetOwner(Player* owner)
{
	mOwner = owner;
}

void Tile::SetUnitCount(unsigned int count)
{
	mUnitCount = count;
}

void Tile::SetSelected(bool selected)
{
	mSelected = selected;
}

void Tile::SetMove(Direction direction, unsigned int amount)
{
	if (mOwner == nullptr)
	{
		std::cout << "Can't move, not owned!" << std::endl; // HACK: Make this more general and less dependant.
	}
	else if (amount > mUnitCount)
	{
		std::cout << "Can't move, too few units!" << std::endl;
	}
	else
	{
		std::cout << "Move set! dir: " << direction << " amount: " << amount << std::endl; // DEBUG
		mMoveDirection = direction;
		mMoveAmount = amount;
	}
}


void Tile::Draw()
{
	Game::GetWindow().draw(mBackground);
	Game::GetWindow().draw(mOutline);

	if (mSelected)
	{
		Game::GetWindow().draw(mSelectOutline);
	}

	if (mOwner)
	{
		sf::CircleShape playerToken(mBackground.getSize().x / 2.f); // TODO: put all these semi-temp vars somewhere good
		playerToken.setFillColor(mOwner->getColor());
		playerToken.setPosition(mBackground.getPosition());

		sf::Text unitcount({ std::to_string(mUnitCount) }, Game::GetFont(), 12u * mBackground.getSize().x / 32u); // MagicNumber: sizes, the ratio is just for rezizing
		unitcount.setPosition(mBackground.getPosition() + sf::Vector2f{ 5 * mBackground.getSize().x / 32u, 8 * mBackground.getSize().x / 32u }); // MagicNumber: text position and sizes

		Game::GetWindow().draw(playerToken);
		Game::GetWindow().draw(unitcount);
	}
}