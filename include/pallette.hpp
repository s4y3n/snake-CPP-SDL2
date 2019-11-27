#include <SDL2/SDL.h>
#include <iostream>
#include "cell_SDL.hpp"
#include <vector>
#include "button.hpp" 
#ifndef PALLETTE_H
#define PALLETTE_H

class Pallette { 
	public :
		Pallette(int W, int H, string Element, TTF_Font* Font, Color origin);
		~Pallette();
		int Launch(SDL_Renderer* rend);
		void Display(SDL_Renderer* rend);
		int pickerclicked(int Bx, int By);
		Color getSelectedColor(int Bx, int By);
		void setCarreColor(Color c);
		Color getNewColor();
	private :
		int w; 
		int h;
		int Wpk;
		int Hpk;
		int Xpk;
		int Ypk;
		int s;
		Cell_SDL Carre;
		Cell_SDL Slider;
		Button OkB;
		Button CancelB;
		Button StringS;
		Color originCL;
		Color newCL;
};

#endif
