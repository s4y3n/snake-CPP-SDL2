#include "cell.hpp"

#ifndef HEAD_H
#define HEAD_H

class Head : public Cell{
	public :
		Head(int W, int H, int X, int Y);
		~Head();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
		void setDirection(DIRECTIONS d);
		int getDirection();
		Cell getnextCell();
	private : 
		int DIRECTION ; 
};

#endif
