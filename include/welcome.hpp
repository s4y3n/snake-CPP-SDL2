#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "functions.hpp"
#include "game.hpp"
#include "button.hpp"
#ifndef WELCOME_H
#define WELCOME_H


class Welcome{
	public :
		Welcome();
		~Welcome();
		int Init();
		void Launch();
		void Quit();
		void DisplayStart();
	private :
		SDL_Window* win;
		SDL_Renderer* rend;
		// Pause Display 
		TTF_Font* Font;
		Button startB;
		// SCORE :
};

#endif
