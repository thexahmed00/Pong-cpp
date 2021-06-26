#pragma once
#include "Graphics.h"
#include "Vec2.h"

class  Rect
{
public:
	
	Rect(int x0,int x1,int y0,int y1)
		: width0(x0),
		  width1(x1),
		  height0(y0),
		height1(y1)
		  
	{
		
	}
	Vec2 pos;
	const int  width0;
	const int  width1;
	const int height0;
	const int height1;
	Rect get_center();

	
	
};
