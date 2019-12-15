//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "window.hpp"
#include "functions.hpp"
#include "button.hpp"
#include "sound.hpp"

#ifndef NEWGAME_H
#define NEWGAME_H

class NewGame {
	public :
		NewGame(int x, int y, TTF_Font* Font);
		~NewGame();
		int Launch(SDL_Renderer* rend, Sound sound);
		void DisplayMainWindow(SDL_Renderer* rend);
	private :
		Window mainWindow;
		Button level1B;
		Button level2B;
		Button level3B;
		Button backB;
};

#endif

