#include "cell_SDL.hpp"

#ifndef EYE_H
#define EYE_H

class Eye : public Cell_SDL{
	public :
		Eye(int W, int H, int X, int Y);
		~Eye();
		void Draw(SDL_Renderer* rend);
};

#endif
