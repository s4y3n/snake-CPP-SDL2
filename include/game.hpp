//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

//#include <SDL2/SDL.h>
#include <SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL_image.h>
//#include <SDL2/SDL_timer.h>
#include <SDL_timer.h>
//#include <SDL2/SDL_ttf.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "functions.hpp"
#include "cell_SDL.hpp"
#include "head.hpp"
#include "snake.hpp"
#include "cible.hpp"
#include "text.hpp"
#include "score.hpp"
#include "configuration.hpp"
#include "sound.hpp"

#ifndef GAME_H
#define GAME_H

class Game{
	public :
		Game(int l);
		~Game();
		void setLevel();
		int Init();
		void setBackGroundColor(COLOR c=BLACK);
		int Launch(SDL_Renderer* rend, Sound S);
		void DrawHead(SDL_Renderer* rend);
	
		void DrawBody(SDL_Renderer* rend);
		void DrawTarget(SDL_Renderer* rend);
		void Pause(SDL_Renderer* rend);
		void Quit();
		void Lost(SDL_Renderer* rend);
	private :
		SDL_TimerID my_timerID;
		int delay ;
		// Pause Display 
		TTF_Font* Font;

		Text pauseText;
		// Lost Display 
		Text lostText;
		// Score Display 
		Text scoreText;

		Snake snake;
		Cible cible;
		Color BackGroundColor;
		// SCORE :
		int level;
		Score score;
};

#endif
