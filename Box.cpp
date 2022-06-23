#include "Box.h"
using namespace std;
square::square(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h)
{

}

square::~square()
{

}

bool square::insquare(int _x, int _y) const
{
	return (_x > x && _y > y && _x < x + w && _y < y + h);
}

SDL_Rect square::createDesRect() const
{
	return { x, y, w, h };
}
