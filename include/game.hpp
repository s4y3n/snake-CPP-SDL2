#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
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
	private :
		SDL_Window* win;
		SDL_Renderer* rend;
		Snake cell;
		


};
