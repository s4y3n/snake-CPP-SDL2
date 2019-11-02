#include "game.hpp" 

using namespace std;

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
	SDL_Event event;
	SDL_UserEvent userevent;
	
	userevent.type = SDL_USEREVENT;
	userevent.code = 0;
	userevent.data1 = NULL;
	userevent.data2 = NULL;

	event.type = SDL_USEREVENT;
	event.user = userevent;
	SDL_PushEvent(&event);
	return(interval);
}

Game::Game() : cell(RECW,RECH,SIZEX/2,SIZEY/2)
{
	win = NULL;
	rend = NULL;
	delay = 1000;
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
	cell.setLimits(SIZEX,SIZEY);
	Cible cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY);
	SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, cell.getHeadColorR(),cell.getHeadColorG(), cell.getHeadColorB(), cell.getHeadColorA());
	SDL_RenderFillRect(rend, cell.getHeadRect());	
	SDL_SetRenderDrawColor(rend, cible.getColorR(),cible.getColorG(), cible.getColorB(), cible.getColorA());
	SDL_RenderFillRect(rend, cible.getRect());	
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	
	SDL_TimerID my_timerID = SDL_AddTimer(delay, my_callbackfunc,0);
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
				case SDL_USEREVENT :
					cell.move();
					break;
				case SDL_KEYDOWN :
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_W :
					case SDL_SCANCODE_UP :
//						cell.moveUp();
						cell.setDirection(UP);
						break ;
					case SDL_SCANCODE_A :
					case SDL_SCANCODE_LEFT :
						//cell.moveLeft();	
						cell.setDirection(LEFT);
						break ;
					case SDL_SCANCODE_S :
					case SDL_SCANCODE_DOWN :
					//	cell.moveDown();
						cell.setDirection(DOWN);
						break ;
					case SDL_SCANCODE_D :
					case SDL_SCANCODE_RIGHT :
					//	cell.moveRight();
						cell.setDirection(RIGHT);
						break ;
					default:
						break;
				}
			}
		}
		SDL_RenderClear(rend);
		// Drow head
		SDL_SetRenderDrawColor(rend, cell.getHeadColorR(),cell.getHeadColorG(), cell.getHeadColorB(), cell.getHeadColorA());
		SDL_RenderFillRect(rend, cell.getHeadRect());

		if(cell.targetReached(cible))
		{
			cible.setNewPosition(cell.getHeadX(), cell.getHeadY());	
		}

		// Drow target
		SDL_SetRenderDrawColor(rend, cible.getColorR(),cible.getColorG(), cible.getColorB(), cible.getColorA());
		SDL_RenderFillRect(rend, cible.getRect());	
	
		// Drow body
		SDL_SetRenderDrawColor(rend, cell.getHeadColorR(),cell.getHeadColorG(), cell.getHeadColorB(), cell.getHeadColorA());
		for(int i = 0 ; i < cell.getBodyCount() ; i++)
		{
			SDL_RenderFillRect(rend, cell.getBodyAt(i));
		}

		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
		SDL_RenderPresent(rend);
//		SDL_Delay(16);
		
	}
	SDL_RemoveTimer(my_timerID);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
