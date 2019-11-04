#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "game.hpp"
//#include "functions.hpp"
//#include "cell.hpp"
//#include "head.hpp"


//#define SIZEX 400
//#define SIZEY 400
//#define RECW SIZEX/20
//#define RECH SIZEY/20

using namespace std;

//SDL_Window* win = NULL;
//SDL_Renderer* rend = NULL;





int main()
{
	Game game;
	if (game.Init())
	{
		game.Quit();
		return 1;
	}
	game.Launch();
	return 0;

}
