#include <SDL2/SDL.h>

#ifndef CELL_H
#define CELL_H

#include "common.hpp"
class Cell {
	public :
		Cell(int W, int H, int X, int Y);
		Cell(const Cell &c);
		~Cell();
		
		SDL_Rect* getRect();
		void setColor(COLOR c);
		int getColorR();
		int getColorG();
		int getColorB();
		int getColorA();
		int getColor(int e);
		void setPosition(int X, int Y);
		void setX(int X);
		int getX();
		void setY(int Y);
		int getY();
		void setW(int W);
		int getW();
		void setH(int H);
		int getH();
		void Draw(SDL_Renderer* rend);
	private :
		int x, y, w , h;
		SDL_Rect rect;
		SDL_Color color;	
};

#endif
