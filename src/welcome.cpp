#include "welcome.hpp"
#include "newGame.hpp"
#include "configure.hpp"

using namespace std;

Welcome::Welcome() : level1B("NEW GAME", 50, SIZEY/4 - 40, SIZEX-100, 80),
										level2B("BEST SCORES", 50, (SIZEY/2) - 40, SIZEX - 100, 80), 
										level3B("CONFIGURE", 50, (3*SIZEY/4) - 40, SIZEX - 100, 80),
										choiceWindow(SIZEX,SIZEY)
{
	win = NULL;
	rend = NULL; 
	Font = NULL;
}

Welcome::~Welcome()
{

}

void Welcome::Quit()
{	
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	if(Font != NULL)
		TTF_CloseFont(Font);
	TTF_Quit();
	level1B.Free();
	level2B.Free();
	level3B.Free();
	SDL_Quit();
}

int Welcome::Init()
{
	Uint32 render_flags = SDL_RENDERER_ACCELERATED ;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0 )
	{
		cout << "Error initializing SDL " << SDL_GetError() << endl;
		return 1;
	}
	win = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZEX, SIZEY, 0);
	if(win == NULL)
	{
		cout << "Error creating choiceWindow : " << SDL_GetError() << endl;
		return 1;
	}
	rend = SDL_CreateRenderer(win, -1, render_flags);
	if(rend == NULL)
	{
		cout << "Error creating renderer :" << SDL_GetError() << endl;
		return 1;
	}
	if(TTF_Init() == -1)
	{
		cout << "Error enable to init TTF : " << TTF_GetError() << endl;
		return 1;
	}
	//Font = TTF_OpenFont("BebasNeue-Regular.ttf", 20);
	Font = TTF_OpenFont("04B_20__.TTF", 50);
	if(Font == NULL)
	{
		cout << "Enable to OpenFont : " << TTF_GetError() << endl;
		return 1;
	}
	level1B.Init(Font);
	level2B.Init(Font);
	level3B.Init(Font);
	choiceWindow.addButton(level1B);
	choiceWindow.addButton(level2B);
	choiceWindow.addButton(level3B);
	SDL_RenderSetLogicalSize(rend,SIZEX,SIZEY);	
	return 0;
}

void Welcome::Launch()
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	DisplayStart();	
	int close = 0;
	int choice = 0;
	while(!close)
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
							choice = 1;
						break;
					default:
						break;
				}
					break;
				case SDL_MOUSEBUTTONDOWN :
					choice = choiceWindow.returnClickedElement(event.button.x, event.button.y);
					break;
			}
		}
		SDL_RenderClear(rend);
		if(choice != 0) //switch case here
		{
			if(choice == 1)
			{		
					choice = 0;
					NewGame newGame(SIZEX,SIZEY,Font);
					close = newGame.Launch(rend);
			}
			else if(choice == 3)
			{
				choice = 0;
				Configure configure(SIZEX, SIZEY, Font);
				close = configure.Launch(rend);
			}
			else
			{
				DisplayStart();
			}
		}
		else 
		{
			DisplayStart();
		}
	}
	Quit();
}

void Welcome::DisplayStart()
{	
	choiceWindow.Display(rend);
}
