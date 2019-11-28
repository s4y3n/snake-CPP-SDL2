//#include <SDL2/SDL.h>
#include <SDL.h>
#include <iostream>
#include "cell.hpp" 
#ifndef CELL_SDL_H
#define CELL_SDL_H

class Cell_SDL : public Cell{
	public :
		Cell_SDL(int W, int H, int X, int Y);
		Cell_SDL(const Cell_SDL &c);
		~Cell_SDL();
		void setColor(COLOR c);
		void chargeColor(Color c); // From config file
		int getColorR();
		int getColorG();
		int getColorB();
		int getColorA();
		int getColor(int e);
		Color getCOLOR(void);
		void setRectX(int X);	
		void setRectY(int Y);
		void setRectW(int W);
		void setRectH(int H);
		int clicked(int x, int y);
		SDL_Rect* getRect();
	private :
		SDL_Rect rect;
		//SDL_Color color;	
		Color color;	
};

#endif
