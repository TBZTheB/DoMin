#pragma once

#include "SDL.h"

struct square
{
	int x;
	int y;
	int w;
	int h;

	square(int _x, int _y, int _w, int _h);
	~square();

	bool insquare(int x, int y) const;
	SDL_Rect createDesRect() const;
};
