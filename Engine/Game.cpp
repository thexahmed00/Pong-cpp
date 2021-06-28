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
#include  "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	pad(Vec2(40,300 ), 15, 60),
	pad2(Vec2(760,300),15,60),
	b(Vec2(400, 300), Vec2(-300.0f, -300.0f)),
	walls(0, Graphics::ScreenWidth, 0, gfx.ScreenHeight)
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
	if (!GameOver) {
		const float dt = ft.Mark();
		pad_moves(wnd.kbd);
		b.Move(dt, walls);
		if (b.get_pos().x < pad.get_pos().x + pad.get_width() &&
			b.get_pos().x >  pad.get_pos().x &&
			b.get_pos().y <  pad.get_pos().y + pad.get_height() &&
			b.get_pos().y >  pad.get_pos().y)
		{
			b.ReboundX();
		}

		if (b.get_pos().x > pad2.get_pos().x &&
			b.get_pos().x <  pad2.get_pos().x + pad2.get_width() &&
			b.get_pos().y >  pad2.get_pos().y &&
			b.get_pos().y < pad2.get_pos().y + pad2.get_height())
		{
			b.ReboundX();
		}
	}
}

void Game::pad_moves(Keyboard& kbd)
{
	constexpr  float wall_down = 540;
	constexpr  float wall_up = 0;

	if (kbd.KeyIsPressed(VK_UP))
	{
		pad.pos.y-= speed;
		if (pad.get_pos().y <= wall_up) {

			pad.pos.y = wall_up;
		}

	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		pad.pos.y += 5;
		if (pad.get_pos().y >= wall_down) {

			pad.pos.y = wall_down;
		}
	}
	//right pad
	if (kbd.KeyIsPressed('W'))
	{
		pad2.pos.y -= speed;
		if (pad2.get_pos().y <= wall_up) {

			pad2.pos.y = wall_up;
		}

	}
	if (kbd.KeyIsPressed('S'))
	{
		pad2.pos.y += 5;
		if (pad2.get_pos().y >= wall_down) {

			pad2.pos.y = wall_down;
		}
	}
	if(b.getWallcollide())
	{
		GameOver = true;
		
	}
}


void Game::ComposeFrame()
{
	if(!GameOver)
	{
		
	pad.draw(gfx, Colors::Gray);
	
	pad2.draw(gfx, Colors::Gray);
	b.draw(gfx);
	}
}

