//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "window.hpp"
#include "functions.hpp"
#include "button.hpp"
#include "configuration.hpp"

#ifndef CONFIGURE_H
#define CONFIGURE_H

class Configure {
	public :
		Configure(int x, int y, TTF_Font* Font);
		~Configure();
		int Launch(SDL_Renderer* rend, TTF_Font* Font);
		void DisplayMainWindow(SDL_Renderer* rend);
	private :
		int W;
		int H;
		Window mainWindow;
		Button headS;
		Button config1B;
		Button config2B;
		Button config3B;
		Button config4B;
		Button backB;
		Configuration config;
};

#endif

