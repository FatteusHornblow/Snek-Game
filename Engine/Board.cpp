#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

Board::~Board()
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	const int offset_x = x + borderWidth + borderPadding;
	const int offset_y = y + borderWidth + borderPadding;
	gfx.DrawRectDim(loc.x * dimension + offset_x + cellPadding, loc.y * dimension + offset_y + cellPadding, dimension - (cellPadding * 2), dimension - (cellPadding * 2), c);
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderPadding + borderWidth) * 2 + height * dimension;
	const int right = left + (borderPadding + borderWidth) * 2 + (width + 1) * dimension;

	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
	//right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x <= width && 
		   loc.y >= 0 && loc.y < height;
}
