#include <SDL2/SDL.h>

#ifndef CELL_H
#define CELL_H

#include "common.hpp"
class Cell {
	public :
		Cell(int W, int H, int X, int Y);
		Cell(const Cell &c);
		~Cell();
		void setPosition(int X, int Y);
		void setX(int X);
		int getX();
		void setY(int Y);
		int getY();
		void setW(int W);
		int getW();
		void setH(int H);
		int getH();
	private :
		int x, y, w , h;
};

#endif
