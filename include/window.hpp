#include <SDL2/SDL.h>
#include "common.hpp"
#include "button.hpp"
#include "text.hpp"
#include <vector>
using namespace std;

#ifndef WINDOW_H
#define WINDOW_H

class Window
{
	public :
		Window(int X, int Y, COLOR c=BLACK);
		~Window();
		void setColor(COLOR c);
		void Display(SDL_Renderer* rend);
		void addButton(Button &b);
		void addText(Text &t);
		void DisplayStatus();
		int returnClickedElement(int X, int Y);
	private :
		int sizex;
		int sizeY;
		int nbrelements; 
		vector<Button> elements;	
		Color color;
};

#endif
