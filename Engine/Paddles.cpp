#include "Paddles.h"

#include <iostream>

#include  "Keyboard.h"
void Paddles::draw( Graphics& gfx,Color c) const
{
	 
	for (int i = pos.x; i < pos.x+width; i++)
	{
		for (int j = pos.y; j < pos.y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::Cyan);
		}
	}

	
}

Vec2 Paddles::get_pos() 
{
	return  pos;
}

int Paddles::get_height() const
{
	return height;
}

int Paddles::get_width() const
{
	return width;
}



bool Paddles::isCollide(ball& b) 
{
	if (b.get_pos().x < pos.x + width &&
		b.get_pos().x > pos.x &&
		b.get_pos().y < pos.y + height &&
		b.get_pos().y > pos.y)
	{
		isCollideBall = true;
	}
	else
	{
		isCollideBall = false;
	}
	return isCollideBall;
}

float Paddles::Getcenter()
{
	return  (width + height) / 2;
}




