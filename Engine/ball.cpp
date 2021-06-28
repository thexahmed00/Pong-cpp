#include "ball.h"
#include "SpriteCodex.h"
#include <random>
void ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void ball::Move(float dt,Rect& wall)
{
	pos += vel * dt;
	if(pos.y+14 >=wall.height1)
	{
		rebound_y();
		
	}

	if ( pos.y-14 <=wall.height0)
	{
		rebound_y();
		//vel.x = -vel.x;
	}
	if (pos.x-14<=wall.width0 )
	{
		ReboundX();
		iswallcollide = true;
		//vel.x = -vel.x;
	}
	if (pos.x+14 >= wall.width1)
	{
		ReboundX();
		iswallcollide = true;
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

bool ball::getWallcollide()
{
	return iswallcollide;
}





