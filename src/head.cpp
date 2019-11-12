#include "head.hpp"

using namespace std;
Head::Head(int W, int H, int X, int Y,COLOR c):Cell_SDL(W,H,X,Y),
	rightE(4,4, X + 3*W/4 - 4/2, Y + H/2 - 4/2),
	leftE(4,4, X + W/4 - 4/2, Y + H/2 - 4/2)
{
	setColor(c);
	DIRECTION = IDLE;
}

Head::~Head()
{

}

void Head::setEyesH()
{
	rightE.setPosition(getX() + (3*getW()/4) - rightE.getW()/2, getY() + getH()/2 - rightE.getH()/2);
	leftE.setPosition(getX() + (getW()/4) - leftE.getW()/2, getY() + getH()/2 - leftE.getH()/2);
}

void Head::setEyesV()
{
	rightE.setPosition(getX() + (getW()/2) - rightE.getW()/2, getY() + (3*getH()/4) - rightE.getH()/2);
	leftE.setPosition(getX() + (getW()/2) - leftE.getW()/2, getY() + (getH()/4) - leftE.getH()/2);
}

void Head::moveUp()
{
	setY(getY() - getH());
	setEyesH();
}

void Head::moveDown()
{
 setY(getY() + getH()); 
	setEyesH();
}

void Head::moveRight()
{
	setX(getX() + getW());
	setEyesV(); 
}

void Head::moveLeft()
{
	setX(getX() - getW()); 
	setEyesV(); 
}

int Head::getDirection()
{
	return DIRECTION;
}

void Head::setDirection(DIRECTIONS d)
{
	DIRECTION = d;
}

Cell_SDL Head::getnextCell()
{
	Cell_SDL cell(getW(),getH(),0,0);
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

void Head::Draw(SDL_Renderer* rend)
{
	setRectX(getX() + 1);
	setRectY(getY() + 1);
	setRectW(getW() - 2);
	setRectH(getH() - 2);
	SDL_SetRenderDrawColor(rend, getColorR(),getColorG(),getColorB(), getColorA());
	SDL_RenderFillRect(rend, getRect());	
	rightE.Draw(rend);
	leftE.Draw(rend);
}
