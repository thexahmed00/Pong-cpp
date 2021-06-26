#pragma once

#include "ball.h"
#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddles
{
public:
	Vec2 pos;
private:
	float width;float height;
	bool isCollideBall = false;
	
public:
	Paddles(const Vec2& pos, float width, float height)
		: pos(pos),
		width(width),
		  height(height)
	{
	}

	void draw(Graphics& gfx,Color c) const;
	Vec2 get_pos();
	int get_height() const;
	int get_width() const;
	
	
	bool isCollide(ball& b) ;
	float Getcenter();
	const float left = pos.x - (width/2);
	const float right = pos.x + (width/2);
	const float  up = pos.y - (height/2);
	const float down = pos.y + (height/2);
};
