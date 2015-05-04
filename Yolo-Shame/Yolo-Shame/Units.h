#pragma once

#include"Player.h"

class Units
{
public:
	Units()  = default;
	~Units() = default;

	Units::Units(Player owner, unsigned int count) : mOwner(owner), mCount(count) {}


	void setOwner(Player player) { mOwner = player; }
	void setCount(unsigned int count) { mCount = count; }

	Player getOwner() { return mOwner; }
	unsigned int getCount() { return mCount; }

private:
	Player mOwner;
	unsigned int mCount;
};

