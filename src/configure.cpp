#include "configure.hpp"
#include <iostream>

using namespace std;

Configure::Configure(int x, int y,TTF_Font* Font) : mainWindow(x,y),
	headS("Configure :", 50, y/4 - 40, x-100, 80),
	config1B("BACKGROUND", 50, y/4 - 40, x-100, 80),
	config2B("HEAD", 50, y/4 - 40, x-100, 80),
	config3B("BODY", 50, y/4 - 40, x-100, 80),
	config4B("TARGET", 50, y/4 - 40, x-100, 80),
	backB("BACK", 50, y/4 - 40, x-100, 80)
{
	headS.Init(Font);
	headS.setUnclickable();
	config1B.Init(Font);
	config2B.Init(Font);
	config3B.Init(Font);
	config4B.Init(Font);
	backB.Init(Font);
	mainWindow.addButton(headS);
	mainWindow.addButton(config1B);
	mainWindow.addButton(config2B);
	mainWindow.addButton(config3B);
	mainWindow.addButton(config4B);
	mainWindow.addButton(backB);
}


Configure::~Configure()
{
	headS.Free();
	config1B.Free();
	config2B.Free();
	config3B.Free();
	config4B.Free();
	backB.Free();
}

int Configure::Launch(SDL_Renderer* rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	mainWindow.Display(rend);
	int close = 0;
	int launch = 0;
	int back = 0;
	while(!close && !back)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT :
					close = 1;
					break;
				case SDL_KEYDOWN :
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						close = 1;
						break;
					case SDL_SCANCODE_SPACE:
							launch = 1;
						break;
					default:
						break;
				}
					break;
				case SDL_MOUSEBUTTONDOWN :
					launch = mainWindow.returnClickedElement(event.button.x, event.button.y);
					break;
			}
		}
		SDL_RenderClear(rend);
		if(launch != 0 && launch != 6)
		{
			cout << "Launch value = " << launch << endl;
			switch(launch)
			{
				case 1 :
						cout << "Clicked on string ! " << endl;
						break;
				case 2:
					cout << "Configure background" << endl;
					break;
				case 3:
					cout << "Configure Head" << endl;
					break;
				case 4:
					cout << "Configure Body" << endl;
					break;
				case 5:
					cout << "Configure Targets" << endl;
					break;
			}
			launch = 0;
		}else if(launch == 6)
		{
			back = 1;
		}
		else
		{
			DisplayMainWindow(rend);
		}
	}
	return close;
}

void Configure::DisplayMainWindow(SDL_Renderer* rend)
{
	mainWindow.Display(rend);
}