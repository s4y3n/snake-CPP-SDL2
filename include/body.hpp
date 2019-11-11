//#include "cell.hpp"

#ifndef BODY_H
#define BODY_H

#include "cell_SDL.hpp"
class Body : public  Cell_SDL{
	public :
		Body(int W, int H, int X, int Y);
		~Body();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
		int inCell(Cell_SDL c);
		void Draw(SDL_Renderer* rend);
		void setOnAtarget(int a);
	private : 
		int DIRECTION ;
		int onATarget; 
};

#endif
