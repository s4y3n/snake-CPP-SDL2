#include "snake.hpp"
using namespace std;

Snake::Snake(int W, int H, int X, int Y) : head(W,H,X,Y)
{
	//head = new Head();
	bodyLength = 0;
	limitX = 0;
	limitY = 0;	
}

Snake::~Snake()
{
	body.clear();
	vector<Body>(body).swap(body);
	targets.clear();
	vector<Cible>(targets).swap(targets);

}

void Snake::setDirection(DIRECTIONS d)
{
	if(head.getDirection() != UP && d == DOWN)
	{	
		head.setDirection(DOWN);		
	}else if(head.getDirection() != DOWN && d == UP)
	{
		head.setDirection(UP);		
	}else if(head.getDirection() != RIGHT && d == LEFT)
	{
		head.setDirection(LEFT);			
	}else if(head.getDirection() != LEFT && d == RIGHT)
	{
		head.setDirection(RIGHT);			
	}
}

void Snake::move()
{
	int dir = head.getDirection();
	if(dir != IDLE)
	{
		switch(dir)
		{
			case UP :
				moveUp();
				break;
			case DOWN :
				moveDown();
				break;
			case LEFT :
				moveLeft();
				break;
			case RIGHT :
				moveRight();
				break;
		}
	}
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
/*
	if(body.size() == 0 && head.getX() == targets.front().getX() && head.getY() == targets.front().getY())
	{
		cout << "HERE" << endl;
		Body tmpBody(targets.front().getW(), targets.front().getH(),targets.front().getX(),targets.front().getY());
		targets.erase(targets.begin());
		body.push_back(tmpBody);
	}
	else if(body.back().getX() == targets.front().getX() && body.back().getY() == targets.front().getY())
	{
		cout << "HERE2" << endl;
		Body tmpBody(targets.front().getW(), targets.front().getH(),targets.front().getX(),targets.front().getY());
		targets.erase(targets.begin());
		body.push_back(tmpBody);
	}
*/
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


int Snake::targetReached(Cible c)
{
//	cout << "head X : " << head.getX() << endl;
//	cout << "head Y : " << head.getY() << endl;
//	cout << "cible X : " << c.getX() << endl;
//	cout << "cible Y : " << c.getY() << endl;
	if(head.getX() == c.getX() && head.getY() == c.getY())
	{
		addTarget(c);
		return 1;
	}
	return 0;
}

void Snake::addTarget(Cible c)
{
	targets.push_back(c);
	cout << "Target acquired : " << targets.size() << endl;
}
 
int Snake::getBodyCount()
{
	return body.size();
}


SDL_Rect* Snake::getBodyAt(int pos)
{
	return body[pos].getRect();
}
