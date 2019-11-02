#include "game.hpp" 

using namespace std;

Game::Game() : cell(RECW,RECH,SIZEX/2,SIZEY/2)
{
	win = NULL;
	rend = NULL;
}

Game::~Game()
{

}


int Game::Init()
{

	Uint32 render_flags = SDL_RENDERER_ACCELERATED ;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0 )
	{
		cout << "Error initializing SDL " << SDL_GetError() << endl;
		return 1;
	}
	win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZEX, SIZEY, 0);
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
	SDL_RenderSetLogicalSize(rend,SIZEX,SIZEY);
	return 0;

}

void Game::Launch()
{

	//*Cell Head */ Snake cell(RECW,RECH,SIZEX/2,SIZEY/2);
	Cible cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY);
	cell.setLimits(SIZEX,SIZEY);
	SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, cell.getHeadColorR(),cell.getHeadColorG(), cell.getHeadColorB(), cell.getHeadColorA());
	SDL_RenderFillRect(rend, cell.getHeadRect());	
	SDL_SetRenderDrawColor(rend, cible.getColorR(),cible.getColorG(), cible.getColorB(), cible.getColorA());
	SDL_RenderFillRect(rend, cible.getRect());	
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	

	int close = 0;
	int speed = 300;
	
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
					case SDL_SCANCODE_W :
					case SDL_SCANCODE_UP :
						cell.moveUp();
						up();
						break ;
					case SDL_SCANCODE_A :
					case SDL_SCANCODE_LEFT :
						cell.moveLeft();	
						break ;
					case SDL_SCANCODE_S :
					case SDL_SCANCODE_DOWN :
						cell.moveDown();
						break ;
					case SDL_SCANCODE_D :
					case SDL_SCANCODE_RIGHT :
						cell.moveRight();
						break ;
					default:
						break;
				}
			}
		}
		SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, cell.getHeadColorR(),cell.getHeadColorG(), cell.getHeadColorB(), cell.getHeadColorA());
		SDL_RenderFillRect(rend, cell.getHeadRect());
		cible.setNewPosition(cell.getHeadX(), cell.getHeadY());	
		SDL_SetRenderDrawColor(rend, cible.getColorR(),cible.getColorG(), cible.getColorB(), cible.getColorA());
		SDL_RenderFillRect(rend, cible.getRect());	
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
		SDL_RenderPresent(rend);
		SDL_Delay(16);
		
	}
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
