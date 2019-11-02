#include "snake.hpp"

Snake::Snake(int W, int H, int X, int Y) : head(W,H,X,Y)
{
	//head = new Head();
	bodyLength = 0;
	limitX = 0;
	limitY = 0;	
}

Snake::~Snake()
{
	//delete head;
}

void Snake::moveBody()
{
	for(int i = body.size() - 1; i >= 0 ; i++)
	{
		if(i == 0)
		{
			body.at(i).setY(head.getY());	
			body.at(i).setX(head.getX());
		}else
		{
			body.at(i).setY(body.at(i-1).getY());
			body.at(i).setX(body.at(i-1).getX());
		}
	}
}

void Snake::setLimits(int XMAX, int YMAX)
{
	limitX = XMAX;
	limitY = YMAX;
}

void Snake::moveUp()
{
	if(head.getDirection() != DOWN && head.getY()  > 0)
	{
		head.setDirection(UP);		
		moveBody();
		head.moveUp();
	}
}
 
void Snake::moveDown()
{
	if(head.getDirection() != UP && head.getY() + head.getH() < limitY)
	{
		head.setDirection(DOWN);		
		moveBody();
		head.moveDown();
	}
}
 
void Snake::moveRight()
{
	if(head.getDirection() != LEFT && head.getX() + head.getW() < limitX)
	{
		head.setDirection(RIGHT);		
		moveBody();
		head.moveRight();
	}
}
 
void Snake::moveLeft()
{
	if(head.getDirection() != RIGHT && head.getX() > 0)
	{
		head.setDirection(LEFT);		
		moveBody();
		head.moveLeft();
	}
}

int Snake::getHeadColorR()
{
	return head.getColorR();
}

int Snake::getHeadColorG()
{
	return head.getColorG();
}

int  Snake::getHeadColorB()
{
	return head.getColorB();
}

int Snake::getHeadColorA()
{
	return head.getColorR();
}

SDL_Rect* Snake::getHeadRect()
{
	return head.getRect();
}

int Snake::getHeadX()
{
	return head.getX();
}
 
int Snake::getHeadY()
{
	return head.getY();
} 
