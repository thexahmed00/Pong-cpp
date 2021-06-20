#include "Paddles.h"

#include <iostream>

#include  "Keyboard.h"
void Paddles::draw( Graphics& gfx,Color c) const
{
	 for (float i=pos.y;i<height+pos.y;i++)
	 {
	 	for (float j = pos.x; j < width+pos.x; j++)
	 	{
	 		gfx.PutPixel(i,j,c);
	 	}
	 }
	
}

Vec2 Paddles::get_pos()
{
	return  pos;
}

void Paddles::move(const Keyboard& kbd)
{
	constexpr  float wall_down=540;
	constexpr  float wall_up = 0;

	if(kbd.KeyIsPressed(VK_UP))
	{
		pos.x-= 5;
		if (pos.x <= wall_up) {

			pos.x = wall_up;
		}
		
	}
	if(kbd.KeyIsPressed(VK_DOWN))
	{
		pos.x+=5;
		if (pos.x >=wall_down) {
			
			pos.x = wall_down;
		}
	}
}


