#include "head.hpp"

Head::Head(int W, int H, int X, int Y):Cell(W,H,X,Y)
{
	setColor(RED);
	DIRECTION = IDLE;
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

int Head::getDirection()
{
	return DIRECTION;
}

void Head::setDirection(DIRECTIONS d)
{
	DIRECTION = d;
}

Cell Head::getnextCell()
{
	Cell cell(getW(),getH(),0,0);
	switch(DIRECTION){
		case UP :
			cell.setPosition(getX(),getY() - getH());
			break;
		case DOWN :
			cell.setPosition(getX(),getY() + getH());
			break;
		case LEFT :
			cell.setPosition(getX() - getW(),getY());
			break;
		case RIGHT :
			cell.setPosition(getX() + getW(),getY());
			break;
	}
	return cell;
}

