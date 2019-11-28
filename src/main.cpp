//#include <SDL2/SDL.h>
#include <SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL_image.h>
//#include <SDL2/SDL_timer.h>
#include <SDL_timer.h>
#include <iostream>
#include "welcome.hpp"

using namespace std;

int main(int argc, char** argv)
{
	Welcome welcome;
	if (welcome.Init())
	{
		welcome.Quit();
		return 1;
	}
	welcome.Launch();
	return 0;

}
