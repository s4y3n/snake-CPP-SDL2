//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "window.hpp"
#include "functions.hpp"
#include "button.hpp"


#ifndef BESTSCORES_H
#define BESTSCORES_H

class BestScores {
	public :
		BestScores(int x, int y, TTF_Font* Font);
		~BestScores();
		int Launch(SDL_Renderer* rend);
		void DisplayMainWindow(SDL_Renderer* rend);
	private :
		Window mainWindow;
		Button headS;
		Button scoreLevel1S;
		Button scoreLevel2S;
		Button scoreLevel3S;
		Button backB;
};

#endif

