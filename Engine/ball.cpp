#include "ball.h"
#include "SpriteCodex.h"
#include <random>
void ball::draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void ball::Move(float dt,Rect& wall)
{
	pos += vel * dt;
	if(pos.y >wall.height1-20)
	{
		vel.y = -vel.y;
		
	}

	if ( pos.y <wall.height0+15 )
	{
		//vel.x = -vel.x;
		vel.y = -vel.y;
	}
	

}


