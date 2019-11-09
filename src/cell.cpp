#include "cell.hpp"

Cell::Cell(int W, int H, int X, int Y) : x(X), y(Y), w(W), h(H)
{
	rect.w = W;
	rect.h = H;
	rect.x = X;
	rect.y = Y;
}

Cell::Cell(const Cell &c)
{
	x = c.rect.x;
	y = c.rect.y;
	w = c.rect.w;
	h = c.rect.h;
	rect.w = c.rect.w;
	rect.h = c.rect.h;
	rect.x = c.rect.x;
	rect.y = c.rect.y;
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
		color.r = 255;
		color.g = 255;
		color.b = 255;
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
}

void Cell::setPosition(int X,int Y)
{
	setX(X);
	setY(Y);
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
	//Temporary 
	//rect.x = getX();
//	rect.y = getY();
	//rect.w = getW();
	//rect.h = getH();
	
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

int Cell::getColor(int e)
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



void Cell::Draw(SDL_Renderer* rend)
{
/*
	rect.x = getX();
	rect.y = getY();
	rect.w = getW();
	rect.h = getH();*/
	SDL_SetRenderDrawColor(rend, color.r,color.g,color.b, color.a);
	SDL_RenderFillRect(rend, &rect);	
}
