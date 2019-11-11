#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream> 
#include <string>
#include "functions.hpp"
#include "cell_SDL.hpp"
#include "head.hpp"
#include "snake.hpp"
#include "cible.hpp"
#include "text.hpp"
#ifndef GAME_H
#define GAME_H
class Game{
	public :
		Game();
		~Game();
		int Init();
		int Launch(SDL_Renderer* rend);
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
//		SDL_Surface *PauseText ;
//		SDL_Color PauseTextColor;
//		SDL_Texture* PauseTextMessage;
//		SDL_Rect PauseTextPosition ;
		// Lost Display 
		Text lostText;
//		SDL_Surface *LostText ;
//		SDL_Color LostTextColor;
//		SDL_Texture* LostTextMessage;
//		SDL_Rect LostTextPosition ;
		// Score Display 
		Text scoreText;
		SDL_Surface *ScoreText ;
		SDL_Color ScoreTextColor;
		SDL_Texture* ScoreTextMessage;
		SDL_Rect ScoreTextPosition ;

		Snake snake;
		Cible cible;
		SDL_Color targetColor;
		// SCORE :
		int score;
};

#endif
