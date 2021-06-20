#pragma once
#include "Graphics.h"
#include "Paddles.h"
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
	void Move(float dt,Rect& wall,Paddles& pad);
	Vec2 get_pos() const;
	void ReboundX();
	void rebound_y();
//	bool isCollide(Paddles& pad);
private :
	Vec2 pos;
	Vec2 vel;
	
	Color c;
	
};
