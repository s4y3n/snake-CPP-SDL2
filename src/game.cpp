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

Game::Game() : snake(RECW,RECH,SIZEX/2,SIZEY/2),
	cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY),
	pauseText("Pause", 50, SIZEY/2 - 40, SIZEX- 100, 80),
	lostText("You Lost !", 50, SIZEY/4, SIZEX - 100, 80),
	scoreText ("0", SIZEX/3, SIZEY/2, SIZEX/4, 80)
{
	delay = 500;
	////// Message init 
	Font = NULL;
	// Score :
	score = 0;
}

Game::~Game()
{

}

void Game::Quit()
{	
	SDL_RemoveTimer(my_timerID);
	if(Font != NULL)
		TTF_CloseFont(Font);
	pauseText.Free();
	lostText.Free();
	scoreText.Free();
}

int Game::Init()
{
	Font = TTF_OpenFont("BebasNeue-Regular.ttf", 15);
	if(Font == NULL)
	{
		cout << "Enable to OpenFont : " << TTF_GetError() << endl;
		return 1;
	}
	pauseText.Init(Font); 
	lostText.Init(Font);
	scoreText.Init(Font);
	snake.setLimits(SIZEX,SIZEY);
	return 0;
}

void Game::DrawHead(SDL_Renderer* rend)
{
	snake.DrawHead(rend);
}

void Game::DrawBody(SDL_Renderer* rend)
{
	snake.DrawBody(rend);
}

void Game::DrawTarget( SDL_Renderer* rend)
{
	cible.Draw(rend);
}

int Game::Launch(SDL_Renderer* rend)
{
	DrawHead(rend);
	DrawTarget(rend);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	
	my_timerID = SDL_AddTimer(delay, my_callbackfunc,0);
	int close = 0;
	int pause = 0;
	int pauseSet = 0;
	int lost = 0;
	int action = 0;	
	while(!close && !lost)
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
					if(!pause && !lost)
					{
						lost = snake.contact();
						if(!lost)
						{
							snake.move();
							snake.getStatus();
							action = 0;
						}
					}
					break;
				case SDL_KEYDOWN :
				switch(event.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
					case SDL_SCANCODE_SPACE:
						if(!lost)
							pause = !pause;
						break;
					case SDL_SCANCODE_W :
					case SDL_SCANCODE_UP :
						if(!action && !pause)
						{
							snake.setDirection(UP);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_A :
					case SDL_SCANCODE_LEFT :
						if(!action && !pause)
						{
							snake.setDirection(LEFT);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_S :
					case SDL_SCANCODE_DOWN :
						if(!action && !pause)
						{
							snake.setDirection(DOWN);
							action = 1;
						}
						break ;
					case SDL_SCANCODE_D :
					case SDL_SCANCODE_RIGHT :
						if(!action && !pause)
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
		if(!pause && !lost)
		{
		// Drow head
			DrawHead(rend);
		// Drow target
			if(snake.targetReached(cible))
			{
				score++;
				do{
						cible.setNewPosition(snake.getHeadX(), snake.getHeadY());	
				}while(snake.testPosition(cible.getX(), cible.getY()));
			}
			DrawTarget(rend);
		// Drow body
			DrawBody(rend);
		// Draw Background 
			SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
			SDL_RenderPresent(rend);		
		}
		else if(pause)
		{
			Pause(rend);
		}
		else 
		{
			Lost(rend);
			SDL_Delay(5000);
		}
	}
	Quit();

	if(close)
		return 0;
	else //lost
		return 1;
}

void Game::Pause(SDL_Renderer* rend)
{
	pauseText.Display(rend);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}

void Game::Lost(SDL_Renderer* rend)
{
	stringstream scoreStr;
	scoreStr << score;
	scoreText.setText(Font, scoreStr.str().c_str());
	scoreText.Display(rend);
	lostText.Display(rend);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}
