#include <SDL2/SDL.h>
#include <iostream>
#include "cell_SDL.hpp"
#include <vector>
#include "button.hpp"
#include "functions.hpp" 
#ifndef	BG_COLOR_H
#define BG_COLOR_H

class BgColor { 
	public :
		BgColor(int W, int H, string Element, TTF_Font* Font, Color origin);
		~BgColor();
		int Launch(SDL_Renderer* rend);
		void Display(SDL_Renderer* rend);
		int pickerclicked(int Bx, int By);
		Color getSelectedColor(int Bx, int By);
		void setBlackChoiceColor(Color c);
		Color getNewColor();
	private :
		int w; 
		int h;
		int Wpk;
		int Hpk;
		int Xpk;
		int Ypk;
		int s;
		Cell_SDL BlackChoice;
		Cell_SDL WhiteChoice;
		Cell_SDL Rect;
		Button OkB;
		Button CancelB;
		Button StringS;
		Color originCL;
		Color newCL;
};

#endif
