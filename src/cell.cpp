//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "cell.hpp"

Cell::Cell(int W, int H, int X, int Y) : x(X), y(Y), w(W), h(H)
{
	x = X;
	y = Y;	
	w = W;
	h = H;
}

Cell::Cell(const Cell &c)
{
	x = c.x;
	y = c.y;
	w = c.w;
	h = c.h;
}

Cell::~Cell()
{

}

void Cell::setPosition(int X,int Y)
{
	setX(X);
	setY(Y);
}

void Cell::setX(int X)
{
		x = X;
}

int Cell::getX()
{
	return x;
}

void Cell::setY(int Y)
{
	y = Y;
}

int Cell::getY()
{
	return y;
}

void Cell::setW(int W)
{
	w = W;
}

int Cell::getW()
{
	return w;
}

void Cell::setH(int H)
{
	h = H;
}

int Cell::getH()
{
	return h;
}
