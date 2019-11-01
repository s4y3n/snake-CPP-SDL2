#include "body.hpp"

Body::Body(int W, int H, int X, int Y):Cell(W,H,X,Y)
{
	setColor(BLUE);
	DIRECTION = 0;
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
