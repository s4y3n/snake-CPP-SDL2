#include "newGame.hpp"
#include "game.hpp"

NewGame::NewGame(int x, int y,TTF_Font* Font) : mainWindow(x,y), 
	level1B("LEVEL 1", 50, y/4 - 40, x-100, 80),
	level2B("LEVEL 2", 50, y/4 - 40, x-100, 80),
	level3B("LEVEL 3", 50, y/4 - 40, x-100, 80),
	backB("BACK", 50, y/4 - 40, x-100, 80)
{
	level1B.Init(Font);
	level2B.Init(Font);
	level3B.Init(Font);
	backB.Init(Font);
	mainWindow.addButton(level1B);
	mainWindow.addButton(level2B);
	mainWindow.addButton(level3B);
	mainWindow.addButton(backB);
}


NewGame::~NewGame()
{
	level1B.Free();
	level2B.Free();
	level3B.Free();
	backB.Free();
}

int NewGame::Launch(SDL_Renderer* rend)
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
		if(launch != 0 && launch != 4)
		{
			Game game(launch) ;
			if(game.Init() != 0)
			{
				close = 1;
			}
			else
			{
				if(game.Launch(rend) == 0)
				{
					close = 1;
				}
				else
				{
					launch = 0;
				}
			}
		}else if(launch == 4)
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

void NewGame::DisplayMainWindow(SDL_Renderer* rend)
{
	mainWindow.Display(rend);
}
