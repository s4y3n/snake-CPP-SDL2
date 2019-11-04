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
	delay = 500;
	////// Message init 
	Font = NULL;
	// Pause display
	PauseText = NULL;
	PauseTextColor = {0,255,0};
	PauseTextPosition.x = 50;
	PauseTextPosition.y = SIZEY/2 - 40;
	PauseTextPosition.w = SIZEX - 100;
	PauseTextPosition.h = 80;
	// Lost Display
	LostText = NULL;
	LostTextColor = {0,255,0};
	LostTextPosition.x = 50;
	LostTextPosition.y = SIZEY/4;
	LostTextPosition.w = SIZEX - 100;
	LostTextPosition.h = 80;
	//Score Display
	ScoreText = NULL;
	ScoreTextColor = {0,255,0};
	ScoreTextPosition.x = 50;
	ScoreTextPosition.y = SIZEY/2;
	ScoreTextPosition.w = SIZEX-100;
	ScoreTextPosition.h = 80;
	
	// COLORS ! 
	bodyColor.r = 0;
	bodyColor.g = 0;
	bodyColor.b = 255;
	bodyColor.a = 0;
	targetColor.r = 0;
	targetColor.g = 255;
	targetColor.b = 0;
	targetColor.a = 0;
	// Score :
	score = 0;
//	scoreStr = NULL;
}

Game::~Game()
{

}

void Game::Quit()
{	
	SDL_RemoveTimer(my_timerID);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	if(Font != NULL)
		TTF_CloseFont(Font);
	TTF_Quit();
	if(PauseText != NULL)
		SDL_FreeSurface(PauseText);
	if(LostText != NULL)
		SDL_FreeSurface(LostText);
	if(ScoreText != NULL)
		SDL_FreeSurface(ScoreText);
	SDL_Quit();
//	cout << "Here" << endl;
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


	if(TTF_Init() == -1)
	{
		cout << "Error enable to init TTF : " << TTF_GetError() << endl;
		return 1;
	}
	Font = TTF_OpenFont("BebasNeue-Regular.ttf", 16);
	if(Font == NULL)
	{
		cout << "Enable to OpenFont : " << TTF_GetError() << endl;
		return 1;
	}
	PauseText = TTF_RenderText_Solid(Font, "Pause", PauseTextColor);
	if(PauseText == NULL)
	{
		cout << "Enable to Open text" << endl;

	}

	LostText = TTF_RenderText_Solid(Font, "Lost !", LostTextColor);
	if(LostText == NULL)
	{
		cout << "Enable to Open text" << endl;

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
		//SDL_SetRenderDrawColor(rend, snake.getBodyColor(1),snake.getBodyColor(2), snake.getBodyColor(3), snake.getBodyColor(4));
		SDL_SetRenderDrawColor(rend, bodyColor.r,bodyColor.g, bodyColor.b, bodyColor.a);
		SDL_RenderFillRect(rend, snake.getBodyAt(i));
	}
}

void Game::DrawTarget(Cible cible)
{
	//SDL_SetRenderDrawColor(rend, cible.getColor(1),cible.getColor(2), cible.getColor(3), cible.getColor(4));
	SDL_SetRenderDrawColor(rend, targetColor.r,targetColor.g, targetColor.b, targetColor.a);
	SDL_RenderFillRect(rend, cible.getRect());	
}

void Game::Launch()
{
	DrawHead();
	Cible cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY);
	DrawTarget(cible);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
	
	my_timerID = SDL_AddTimer(delay, my_callbackfunc,0);
	int close = 0;
	int pause = 0;
	int lost = 0;
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
			DrawHead();
		// Drow target
			if(snake.targetReached(cible))
			{
				score++;
				cible.setNewPosition(snake.getHeadX(), snake.getHeadY());	
			}
			DrawTarget(cible);
		// Drow body
			DrawBody();
		// Draw Background 
			SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
			SDL_RenderPresent(rend);		
		}
		else if(pause)
		{
			Pause();
		}
		else 
		{
			Lost();
		}
	}
	Quit();
}

void Game::Pause()
{
	PauseTextMessage = SDL_CreateTextureFromSurface(rend,PauseText);
	SDL_RenderCopy(rend,PauseTextMessage,NULL,&PauseTextPosition);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}

void Game::Lost()
{
	stringstream scoreStr;
	scoreStr << score;
	ScoreText = TTF_RenderText_Solid(Font, scoreStr.str().c_str(), LostTextColor);
	if(ScoreText == NULL)
	{
		cout << "Enable to set scoreText" << endl;
	}
	
	ScoreTextMessage = SDL_CreateTextureFromSurface(rend,ScoreText);
	SDL_RenderCopy(rend,ScoreTextMessage,NULL,&ScoreTextPosition);

	LostTextMessage = SDL_CreateTextureFromSurface(rend,LostText);
	SDL_RenderCopy(rend,LostTextMessage,NULL,&LostTextPosition);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}
