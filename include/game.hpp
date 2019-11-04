#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "functions.hpp"
#include "cell.hpp"
#include "head.hpp"
#include "snake.hpp"
#include "cible.hpp"

#define SIZEX 400
#define SIZEY 400
#define RECW SIZEX/20
#define RECH SIZEY/20

class Game{
	public :
		Game();
		~Game();
		int Init();
		void Launch();
		void DrawHead();
		void DrawBody();
		void DrawTarget(Cible cible);
		void Pause();
		void Quit();
		void Lost();
	private :
		SDL_Window* win;
		SDL_Renderer* rend;
		SDL_TimerID my_timerID;
		int delay ;
		// Pause Display 
		TTF_Font* Font;
		SDL_Surface *PauseText ;
		SDL_Color PauseTextColor;
		SDL_Texture* PauseTextMessage;
		SDL_Rect PauseTextPosition ;
		// Pause Display 
		SDL_Surface *LostText ;
		SDL_Color LostTextColor;
		SDL_Texture* LostTextMessage;
		SDL_Rect LostTextPosition ;
		// Lost Display 
		Snake snake;
		SDL_Color bodyColor ;
		SDL_Color targetColor;
};
