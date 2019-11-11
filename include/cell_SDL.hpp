#include <SDL2/SDL.h>
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
		int getColorR();
		int getColorG();
		int getColorB();
		int getColorA();
		int getColor(int e);
		void setRectX(int X);	
		void setRectY(int Y);
		void setRectW(int W);
		void setRectH(int H);

		SDL_Rect* getRect();
	private :
		SDL_Rect rect;
		//SDL_Color color;	
		Color color;	
};

#endif
