#include <SDL2/SDL.h>

#ifndef CELL_H
#define CELL_H
enum COLOR {BLACK, WHITE, RED, BLUE, GREEN};
class Cell {
	public :
		Cell(int W, int H, int X, int Y);
		~Cell();
		
		SDL_Rect* getRect();
		void setColor(COLOR c);
		int getColorR();
		int getColorG();
		int getColorB();
		int getColorA();
		void setX(int X);
		int getX();
		void setY(int Y);
		int getY();
		void setW(int W);
		int getW();
		void setH(int H);
		int getH();
	private :
		SDL_Rect rect;
		SDL_Color color;	
};

#endif
