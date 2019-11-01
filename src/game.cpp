#include "game.hpp" 

using namespace std;

Game::Game()
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

	/*Cell*/Head cell(RECW,RECH,50,50);
	SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, cell.getColorR(),cell.getColorG(), cell.getColorB(), cell.getColorA());
	SDL_RenderFillRect(rend, cell.getRect());	
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
	if(cell.getX() + cell.getW() > SIZEX)
		cell.setX(SIZEX - cell.getW());
	if(cell.getX() < 0)
		cell.setX(0);
	if(cell.getY() + cell.getH() > SIZEX)
		cell.setY(SIZEY - cell.getH());
	if(cell.getY() < 0)
		cell.setY(0);
		
		SDL_RenderClear(rend);
		SDL_SetRenderDrawColor(rend, cell.getColorR(),cell.getColorG(), cell.getColorB(), cell.getColorA());
		SDL_RenderFillRect(rend, cell.getRect());	
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
		SDL_RenderPresent(rend);
		SDL_Delay(16);
		
	}
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
