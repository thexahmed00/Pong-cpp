#include "Paddles.h"
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
