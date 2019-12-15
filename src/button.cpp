//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include <iostream>
#include "button.hpp"
using namespace std;

Button::Button(string t, int X, int Y, int W, int H) :
		Text(t, X, Y, W, H)
{
	clickable = 1;
}

Button::Button(const Button &b) : Text(b)
{
	clickable = b.clickable;
}

Button::~Button()
{


}

void Button::Draw(SDL_Renderer* rend, int Max)
{
	Display(rend,Max);
	if(clickable)
	{
		SDL_SetRenderDrawColor(rend, 255,255,255,255);
		SDL_RenderDrawRect(rend, getRect());	
	}

}


int Button::isClicked(int x, int y)
{
	if(x >= getX() && x <= getX() + getW() && y >= getY() && y <= getY() + getH() && clickable)
		return 1;

	return 0;
}

void Button::show()
{
	cout << "************" << endl;
	cout << "X = " << getX() << endl ;
	cout << "Y = " << getY() << endl ;
	cout << "W = " << getW() << endl ;
	cout << "H = " << getH() << endl ;

}

void Button::setUnclickable()
{
	clickable = 0;
}
