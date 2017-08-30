#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include <random>

class Food
{
public:
	Food(std::mt19937& rng, Board& brd, Snake& snake);
	~Food();
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board& brd) const;
	const Location& GetLocation() const;
private:
	Location loc;
	static constexpr Color c = Colors::Red;
};