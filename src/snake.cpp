#include "snake.hpp"
using namespace std;

Snake::Snake(int W, int H, int X, int Y) : head(W,H,X,Y)
{
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

void Snake::setLimits(int XMAX, int YMAX)
{
	limitX = XMAX;
	limitY = YMAX;
}

void Snake::createBody(int i)
{
	for(int j = 0; j < i; j++)
	{
		Body tmpBody(head.getW(),head.getH(),head.getX(),head.getY()*(j+1) + head.getH());
		body.push_back(tmpBody);
	}
}

void Snake::createBodyElement()
{
	cout << "Adding new element" << endl;
	Body tmpBody(targets.at(0).getW(), targets.at(0).getH(), targets.at(0).getX(), targets.at(0).getY()); 
	body.push_back(tmpBody);
	targets.erase(targets.begin());
}

int Snake::targetOutOfBody()
{
	int outOfBody = 1;
	if(targets.size() == 0)
	{
		outOfBody = 0;
	}
	else if(body.size() == 0 ) 
	{
		if(head.getX() == targets.at(0).getX() && head.getY() == targets.at(0).getY())
			outOfBody = 0;
	}
	else
	{
		for(int i = 0; i < body.size() ; i++)
		{
			if(body.at(i).getX() == targets.at(0).getX() && body.at(i).getY() == targets.at(0).getY())
			{
				outOfBody = 0;
				break;
			}	
		}
	}
	return outOfBody;
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
	if(targetOutOfBody())
	{
		createBodyElement();
		getStatus();
	}
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


void Snake::moveBody()
{
	for(int i = body.size() - 1; i >= 0 ; i--)
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

int Snake::getHeadColor(int e)
{
	return head.getColor(e);
}

int Snake::getBodyColor(int e)
{
	return body.at(0).getColor(e);
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

void Snake::getStatus()
{
	cout << "Head : " << endl;
	cout << "HX = " << head.getX() << endl;
	cout << "HY = " << head.getY() << endl;
	cout << "Body count : " << body.size() << endl;
	for(int i = 0; i < body.size();i++)
	{
		cout << "Body element : " << i << endl;
		cout << "X = " << body.at(i).getX() << endl; 
		cout << "Y = " << body.at(i).getY() << endl; 
	}
	cout << "targets count : " << targets.size() << endl;
}

int Snake::contact()
{
		Cell nextCell(head.getnextCell());
		cout << "Next cell " << endl;
		cout <<"X = " << nextCell.getX() << endl;
		cout <<"Y = " << nextCell.getY() << endl;
	if(head.getY() == 0 && head.getDirection() == UP)
	{
		return 1;
	}else if(head.getY() == limitY - head.getH() && head.getDirection() == DOWN)
	{
		return 1;
	}else if(head.getX() == limitX - head.getW() && head.getDirection() == RIGHT)
	{
		return 1;
	}else if(head.getX() == 0 && head.getDirection() == LEFT)
	{
			return 1;
	}else if(body.size() != 0) // Test head contact with body
	{
		for(int i = 0 ; i < body.size() ; i++)
		{
			if(body.at(i).inCell(nextCell))
				return 1;
		}
	}
	return 0;
}
 
