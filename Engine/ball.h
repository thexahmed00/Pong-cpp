#pragma once
#include "Graphics.h"
#include "Rect.h"
#include "Vec2.h"


class ball
{
public:
	ball(const Vec2& pos, const Vec2& vel)
		: pos(pos),
		  vel(vel)
	
	{
		
	}
	void draw(Graphics& gfx) const;
	void Move(float dt,Rect& wall);
	Vec2 get_pos() const;
	void ReboundX();
	void rebound_y();
	
private :
	Vec2 pos;
	Vec2 vel;
	
	Color c;
public :
	const float left = pos.x - 7;
	const float right = pos.x + 7;
	const float  up= pos.y - 7;
	const float down = pos.y + 7;

};
