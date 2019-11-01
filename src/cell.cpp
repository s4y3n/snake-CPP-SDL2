#include "cell.hpp"

Cell::Cell(int W, int H, int X, int Y)
{
	rect.w = W;
	rect.h = H;
	rect.x = X;
	rect.y = Y;
//	color.r = 0; // BLACK
//	color.g = 0;
//	color.b = 0;
//	color.a = 0;
}

Cell::~Cell()
{

}

void Cell::setColor(COLOR c)
{
	if(c == WHITE)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 255;
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
		color.a = 255;
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
}

void Cell::setX(int X)
{
	rect.x = X;
}

int Cell::getX()
{
	return rect.x;
}

void Cell::setY(int Y)
{
	rect.y = Y;
}

int Cell::getY()
{
	return rect.y;
}

void Cell::setW(int W)
{
	rect.w = W;
}

int Cell::getW()
{
	return rect.w;
}

void Cell::setH(int H)
{
	rect.h = H;
}

int Cell::getH()
{
	return rect.h;
}

SDL_Rect* Cell::getRect()
{
	return &rect;
}

int Cell::getColorR()
{
	return color.r;
}

int Cell::getColorG()
{
	return color.g;
}

int Cell::getColorB()
{
	return color.b;
}

int Cell::getColorA()
{
	return color.a;
}
