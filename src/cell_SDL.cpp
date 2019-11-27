#include "cell_SDL.hpp"

using namespace std;

Cell_SDL::Cell_SDL(int W, int H, int X, int Y) : Cell(W,H,X,Y)
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;
}

Cell_SDL::Cell_SDL(const Cell_SDL &c) : Cell(c)
{
	color.r = c.color.r;
	color.g = c.color.g;
	color.b = c.color.b;
	color.a = c.color.a;
}

Cell_SDL::~Cell_SDL()
{

}

void Cell_SDL::setColor(COLOR c)
{
	if(c == WHITE)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 0;
	}
	else if(c == BLACK)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
	else if(c == GREEN)
	{
		color.r = 0;
		color.g = 255;
		color.b = 0;
		color.a = 0;
	}
	else if(c == BLUE)
	{
		color.r = 0;
		color.g = 0;
		color.b = 255;
		color.a = 0;
	}
	else if(c == RED)
	{
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
	else // DEfault RED
	{
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
}

void Cell_SDL::chargeColor(Color c)
{
	color.r = c.r;
	color.g = c.g;
	color.b = c.b;
	color.a = c.a;
}

int Cell_SDL::getColorR()
{
	return color.r;
}

int Cell_SDL::getColorG()
{
	return color.g;
}

int Cell_SDL::getColorB()
{
	return color.b;
}

int Cell_SDL::getColorA()
{
	return color.a;
}

int Cell_SDL::getColor(int e)
{
	switch(e)
	{
		case 1:
			return getColorR();
			break;
		case 2:
			return getColorG();
			break;
		case 3:
			return getColorB();
			break;
		case 4:
			return getColorA();
			break;
	}
	return 0;
}

void Cell_SDL::setRectX(int X)
{
	rect.x = X;
}

void Cell_SDL::setRectY(int Y)
{
	rect.y = Y;
}

void Cell_SDL::setRectW(int W)
{
	rect.w = W;
}

void Cell_SDL::setRectH(int H)
{
	rect.h = H;
}

SDL_Rect* Cell_SDL::getRect()
{
	return &rect;
}


Color Cell_SDL::getCOLOR(void)
{
	return color;
}

int Cell_SDL::clicked(int x, int y)
{
	int isClicked = 0;
	if(x >= getX() && x <= getX() + getW() && y >= getY() && y <= getY() + getH())
		isClicked = 1;
	return isClicked;


}

