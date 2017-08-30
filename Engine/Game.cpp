/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()()),
	snek({brd.GetGridWidth() / 2, brd.GetGridHeight() / 2}),
	food(rng, brd, snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isStarted = true;
	}
	if (!gameIsOver && isStarted)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}

		++snekMoveCounter;
		if (snekMoveCounter > snekMovePeriod)
		{
			snekMoveCounter = 0;
			Location next(snek.GetNextHeadLocation(delta_loc));
			if (!brd.IsInsideBoard(next) || snek.IsInTile(next))
			{
				gameIsOver = true;
			}
			else
			{
				bool isEating = next == food.GetLocation();
				if (isEating)
				{
					snek.Grow();
					++foodCounter;
				}
				snek.MoveBy(delta_loc);
				if (isEating)
				{
					food.Respawn(rng, brd, snek);
				}
				if (foodCounter % 5 == 0 && isEating)
				{
					--snekMovePeriod;
				}
				if (snekMovePeriod < 4)
				{
					snekMovePeriod = 4;
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		SpriteCodex::DrawTitle((gfx.ScreenWidth / 2) - (213 / 2), (gfx.ScreenHeight / 2) - (160 / 2), gfx);
	}
	if (gameIsOver)
	{
		SpriteCodex::DrawGameOver((gfx.ScreenWidth / 2) - (83 / 2), (gfx.ScreenHeight / 2) - (63 / 2), gfx);
	}
	if (isStarted)
	{
		snek.Draw(brd);
		food.Draw(brd);
		brd.DrawBorder();
	}
}