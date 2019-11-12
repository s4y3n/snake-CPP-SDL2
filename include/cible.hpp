//#include "cell.hpp"
#include "cell_SDL.hpp"
//#include "snake.hpp"
#ifndef CIBLE_H
#define CIBLE_H

class Cible : public Cell_SDL{
	public :
		Cible(int W, int H, int X, int Y, int XMAX, int YMAX, COLOR c=GREEN);
		~Cible();
		void setNewPosition(int X, int Y);
		void Draw(SDL_Renderer* rend);
	//	void setNewPos(Snake s);
	private : 
		int DIRECTION ;
		int active ; 
		int Xmax;
		int Ymax;
};

#endif
