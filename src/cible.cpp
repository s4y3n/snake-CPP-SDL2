#include "cible.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Cible::Cible(int W, int H, int X, int Y, int XMAX, int YMAX):Cell(W,H,X,Y)
{
	srand(time(NULL));
	setColor(RED);
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
		if( x%getW() != 0)
			x = x - x%getW();
		y = rand()%Ymax;
		if( y%getH() != 0)
			y = y - y%getH();
		if(x != X || y != Y)
			found = 1;
	}
	setX(x);
	setY(y);
}
