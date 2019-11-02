#include "cible.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Cible::Cible(int W, int H, int X, int Y, int XMAX, int YMAX):Cell(W,H,X,Y)
{
	srand(time(NULL));
	setColor(BLUE);
	DIRECTION = 0 ; // to get rid of 
	active = 1;
	Xmax = XMAX;
	Ymax = YMAX;
	setNewPosition(X,Y);	
}

Cible::~Cible()
{

}

void Cible::setNewPosition(int X, int Y)
{
	int found = 0;
	int x, y;
	while(!found)
	{
		x = rand()%Xmax;
		y = rand()%Ymax;
		if(x != X || y != Y)
			found = 1;
	}
	setX(x);
	setY(y);
}
