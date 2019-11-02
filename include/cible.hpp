#include "cell.hpp"

#ifndef CIBLE_H
#define CIBLE_H

class Cible : public Cell{
	public :
		Cible(int W, int H, int X, int Y, int XMAX, int YMAX);
		~Cible();
		void setNewPosition(int X, int Y);
//		void moveUp();
//		void moveDown();
//		void moveRight();
//		void moveLeft();
//		void setDirection(DIRECTIONS d);
//		int getDirection();
	private : 
		int DIRECTION ;
		int active ; 
		int Xmax;
		int Ymax;
};

#endif
