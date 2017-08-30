#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	~Board();
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	Graphics& gfx;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 27;
	static constexpr int height = 27;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int x = 100;
	static constexpr int y = 20;
	
	//int x = (gfx.ScreenWidth / 2) - ((width * dimension) + ((borderWidth + borderPadding) * 2) / 2);
	//int y = (gfx.ScreenHeight / 2) - ((height * dimension) + ((borderWidth + borderPadding) * 2) / 2);
};

