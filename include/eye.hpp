//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "cell_SDL.hpp"

#ifndef EYE_H
#define EYE_H

class Eye : public Cell_SDL{
	public :
		Eye(int W, int H, int X, int Y, COLOR c=BLACK);
		~Eye();
		void Draw(SDL_Renderer* rend);
};

#endif
