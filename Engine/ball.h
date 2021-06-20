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
	void draw(Graphics& gfx);
	void Move(float dt,Rect& wall);

private :
	Vec2 pos;
	Vec2 vel;
	
	Color c;
	
};
