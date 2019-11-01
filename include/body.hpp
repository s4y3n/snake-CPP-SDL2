#include "cell.hpp"

#ifndef BODY_H
#define BODY_H

class Body : public Cell{
	public :
		Body(int W, int H, int X, int Y);
		~Body();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
	private : 
		int DIRECTION ; 
};

#endif
