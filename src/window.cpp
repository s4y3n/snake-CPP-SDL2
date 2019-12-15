//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "window.hpp"
#include <iostream>

using namespace std;

Window::Window(int X, int Y, COLOR c)
{
	sizex = X;
	sizeY = Y;
	nbrelements = 0;
	max = 0;
	setColor(c);
}

Window::~Window()
{
	elements.clear();
	vector<Button>(elements).swap(elements);
}

void Window::setColor(COLOR c)
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

void Window::addButton(Button &b)
{
	nbrelements++;
	int marge = 25;
	int newH = (sizeY - 2*marge)/(2*nbrelements - 1);
	int i = 0;
	for(i = 0; i < elements.size() ; i++)
	{
		elements[i].setH(newH);
		if(i == 0)
		{
			elements[i].setY(marge);
		}
		else
		{
			elements[i].setY(elements[i - 1].getY() + 2*newH);
		}
	}
	b.setH(newH);
	if(max < b.getTexteSize())
		max = b.getTexteSize();
	if(i == 0)
	{
			b.setY(marge);
	}
	else
	{
		b.setY(elements[i-1].getY() + 2 *newH);
	}
	elements.emplace_back(b);
}


void Window::addText(Text &t)
{
/*
	nbrelements++;
	int newH = sizeY/nbrelements;
	int i = 0;
	for(i = 0; i < elements.size() ; i++)
	{
		elements[i].setH(newH);
		elements[i].setY(i*newH);
	}
	t.setH(newH);
	t.setY(i*newH);
	elements.push_back(t);
*/
}


void Window::Display(SDL_Renderer* rend)
{
	for(int i = 0; i < elements.size() ; i++)
	{
		elements[i].Draw(rend,max);
	}
	SDL_SetRenderDrawColor(rend, color.r, color.g, color.b, color.a);
	SDL_RenderPresent(rend);
}

void Window::DisplayStatus()
{
	for(int i = 0; i < elements.size() ; i++)
	{
		cout << "Element : " << i << endl;
		cout << "X = : " << elements[i].getX() << endl;
		cout << "Y = : " << elements[i].getY() << endl;
		cout << "W = : " << elements[i].getW() << endl;
		cout << "H = : " << elements[i].getH() << endl;

	}
}

int Window::returnClickedElement(int X, int Y)
{
	for(int i = 0; i < elements.size() ; i++)
	{
		if(elements[i].isClicked(X,Y))
			return i + 1;
	}
	return 0;
}
