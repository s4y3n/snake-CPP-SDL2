#include "welcome.hpp"
#include "game.hpp"
using namespace std;

Welcome::Welcome() : startB("Start", 50, SIZEY/2 - 40, SIZEX-100, 80) 
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
	startB.Free();
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
		cout << "Error creating window : " << SDL_GetError() << endl;
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
	Font = TTF_OpenFont("BebasNeue-Regular.ttf", 15);
	if(Font == NULL)
	{
		cout << "Enable to OpenFont : " << TTF_GetError() << endl;
		return 1;
	}
	startB.Init(Font);
	SDL_RenderSetLogicalSize(rend,SIZEX,SIZEY);	
	return 0;
}

void Welcome::Launch()
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	DisplayStart();	
	int close = 0;
	int launch = 0;
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
							launch = 1;
						break;
					default:
						break;
				}
					break;
				case SDL_MOUSEBUTTONDOWN :
//					cout << "Button x " << event.button.x << endl;
//				cout << "Button y " << event.button.y << endl;
					if(startB.isClicked(event.button.x, event.button.y))
						launch = 1;
					break;
			}
		}
		SDL_RenderClear(rend);
		if(launch) //Launch game
		{
			Game game;
			if(game.Init() != 0)
			{
				close = 1;
			}else
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
	startB.Draw(rend);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}
