#include "head.hpp"

Head::Head(int W, int H, int X, int Y):Cell(W,H,X,Y)
{
	setColor(RED);
	DIRECTION = 0;
}

Head::~Head()
{

}

void Head::moveUp()
{
 setY(getY() - getH()); 
}

void Head::moveDown()
{
 setY(getY() + getH()); 
}

void Head::moveRight()
{
 setX(getX() + getW()); 
}

void Head::moveLeft()
{
 setX(getX() - getW()); 
}
