#include "window.hpp"
#include <iostream>

using namespace std;

Window::Window(int X, int Y, COLOR c)
{
	sizex = X;
	sizeY = Y;
	nbrelements = 0;
	setColor(c);
}

Window::~Window()
{



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
	cout << "Adding element : " << nbrelements << endl;
	int newH = sizeY/nbrelements;
	cout << "newH = " << newH << endl;
	int i = 0;
	for(i = 0; i < elements.size() ; i++)
	{
		cout << "Setting : " << i << endl;
		elements[i].setH(newH);
		elements[i].setY(i*newH);
		cout << elements[i].getH() << endl;
		cout << elements[i].getY() << endl;
	}
	b.setH(newH);
	b.setY(i*newH);
	elements.emplace_back(b);
	//DisplayStatus();
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
		elements[i].Draw(rend);
//		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
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
