#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "welcome.hpp"

using namespace std;

int main()
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
