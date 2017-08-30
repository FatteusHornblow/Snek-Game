#include "Food.h"

Food::Food(std::mt19937 & rng, Board & brd, Snake & snake)
{
	Respawn(rng, brd, snake);
}

Food::~Food()
{
}

void Food::Respawn(std::mt19937 & rng, Board & brd, Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));
	loc = newLoc;
}

void Food::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Food::GetLocation() const
{
	return loc;
}
