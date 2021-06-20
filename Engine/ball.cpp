#include "ball.h"
#include "SpriteCodex.h"
#include <random>
void ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void ball::Move(float dt,Rect& wall,Paddles& pad)
{
	pos += vel * dt;
	if(pos.y >wall.height1-12)
	{
		rebound_y();
		
	}

	if ( pos.y <wall.height0+12)
	{
		rebound_y();
		//vel.x = -vel.x;
	}
	if (pos.x<wall.width0+10 )
	{
		ReboundX();
		//vel.x = -vel.x;
	}
	if (pos.x > wall.width1-12)
	{
		ReboundX();
		//vel.x = -vel.x;
	}
	

}

Vec2 ball::get_pos() const
{
	return pos;
}

void ball::ReboundX()
{
	vel.x = -vel.x;
}

void ball::rebound_y()
{
	vel.y = -vel.y;
}



