#include "cell_SDL.hpp"
#include "eye.hpp"
#include "configuration.hpp"
#ifndef HEAD_H
#define HEAD_H

class Head : public Cell_SDL{
	public :
		Head(int W, int H, int X, int Y, COLOR c=RED);
		~Head();
		void setEyesH();
		void setEyesV();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
		void setDirection(DIRECTIONS d);
		int getDirection();
		Cell_SDL getnextCell();
		void Draw(SDL_Renderer* rend);
	private : 
		int DIRECTION ; 
		Eye rightE;
		Eye leftE;
};

#endif
