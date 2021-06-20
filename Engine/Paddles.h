#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddles
{
private:
	Vec2 pos;
	int width;int height;
	bool isCollideBall = false;
	
public:
	Paddles(const Vec2& pos, int width, int height)
		: pos(pos),
		width(width),
		  height(height)
	{
	}

	void draw(Graphics& gfx,Color c) const;
	Vec2 get_pos() const;
	int get_height() const;
	void move(const Keyboard& kbd);
	
};
