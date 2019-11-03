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

Game::Game() : snake(RECW,RECH,SIZEX/2,SIZEY/2)
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
	SDL_RenderSetLogicalSize(rend,SIZEX,SIZEY);
	
	snake.setLimits(SIZEX,SIZEY);
	return 0;

}

void Game::DrawHead()
{
	SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, snake.getHeadColor(1),snake.getHeadColor(2), snake.getHeadColor(3), snake.getHeadColor(4));
	SDL_RenderFillRect(rend, snake.getHeadRect());	
}

void Game::DrawBody()
{
	for(int i = 0 ; i < snake.getBodyCount() ; i++)
	{
		SDL_SetRenderDrawColor(rend, snake.getBodyColor(1),snake.getBodyColor(2), snake.getBodyColor(3), snake.getBodyColor(4));
		SDL_RenderFillRect(rend, snake.getBodyAt(i));
	}
}

void Game::Launch()
{
	DrawHead();
	Cible cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY);
	SDL_SetRenderDrawColor(rend, cible.getColor(1),cible.getColor(2), cible.getColor(3), cible.getColor(4));
	SDL_RenderFillRect(rend, cible.getRect());	
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	
	SDL_TimerID my_timerID = SDL_AddTimer(delay, my_callbackfunc,0);
	int close = 0;
	int action = 0;	
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
					snake.move();
					action = 0;
					break;
				case SDL_KEYDOWN :
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_W :
					case SDL_SCANCODE_UP :
						if(!action)
						{
							snake.setDirection(UP);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_A :
					case SDL_SCANCODE_LEFT :
						if(!action)
						{
							snake.setDirection(LEFT);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_S :
					case SDL_SCANCODE_DOWN :
						if(!action)
						{
							snake.setDirection(DOWN);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_D :
					case SDL_SCANCODE_RIGHT :
						if(!action)
						{
							snake.setDirection(RIGHT);
							action = 1;
						}
						break ;
					default:
						break;
				}
			}
		}
		SDL_RenderClear(rend);
		// Drow head
		DrawHead();
		// Drow target
		if(snake.targetReached(cible))
		{
			cible.setNewPosition(snake.getHeadX(), snake.getHeadY());	
		}
		SDL_SetRenderDrawColor(rend, cible.getColorR(),cible.getColorG(), cible.getColorB(), cible.getColorA());
		SDL_RenderFillRect(rend, cible.getRect());	
		// Drow body
		DrawBody();
		// Draw Background 
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
		SDL_RenderPresent(rend);
//		SDL_Delay(16);
		
	}
	SDL_RemoveTimer(my_timerID);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
