#include "body.hpp"
using namespace std;
Body::Body(int W, int H, int X, int Y, COLOR c):Cell_SDL(W,H,X,Y)
{
	setColor(c);
	DIRECTION = 0;
	onATarget = 0;
}

Body::~Body()
{

}

void Body::moveUp()
{
 setY(getY() - getH()); 
}

void Body::moveDown()
{
 setY(getY() + getH()); 
}

void Body::moveRight()
{
 setX(getX() + getW()); 
}

void Body::moveLeft()
{
 setX(getX() - getW()); 
}

int Body::inCell(Cell_SDL c)
{
	int result = 0;
	if(c.getX() == getX() && c.getY() == getY())
		result = 1;
	return result;
}

void Body::setOnAtarget(int a)
{
	onATarget = a;
}

void Body::Draw(SDL_Renderer* rend)
{
	if(onATarget)
	{
		setRectX(getX());
		setRectY(getY());
		setRectW(getW());
		setRectH(getH());
	}
	else
	{
		setRectX(getX() + 1);
		setRectY(getY() + 1);
		setRectW(getW() - 2);
		setRectH(getH() - 2);
	}
	SDL_SetRenderDrawColor(rend, getColorR(),getColorG(),getColorB(), getColorA());
	SDL_RenderFillRect(rend, getRect());	
}
