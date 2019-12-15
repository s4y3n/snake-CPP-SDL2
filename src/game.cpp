//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "game.hpp"
#include "sound.hpp"

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

Game::Game(int l) : snake(RECW,RECH,SIZEX/2,SIZEY/2),
	cible(RECW,RECH,SIZEX/2, SIZEY/2,SIZEX, SIZEY, GREEN),
	pauseText("Pause", 50, SIZEY/2 - 40, SIZEX- 100, 80),
	lostText("You Lost !", 50, SIZEY/4, SIZEX - 100, 80),
	scoreText ("0", SIZEX/3, SIZEY/2, SIZEX/4, 80),
	score(l)
{
	level = l;
	setLevel();
	////// Message init 
	Font = NULL;
	setBackGroundColor();	
}



Game::~Game()
{

}

void Game::setLevel()
{
	switch(level)
	{
		case 1:
			delay = 1000;
			break;
		case 2:
			delay = 500;
			break;
		case 3:
			delay = 250;
			break;
		default :
			delay = 1000;
	}
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

void Game::setBackGroundColor(COLOR c)
{
	Configuration config;
	if(config.gotConfig())
	{
		Color c = config.getBackGroundColor();
		BackGroundColor.r = c.r;
		BackGroundColor.g = c.g;
		BackGroundColor.b = c.b;
		BackGroundColor.a = c.a;
	}
	else
	{
		if(c == WHITE)
		{
			BackGroundColor.r = 255;
			BackGroundColor.g = 255;
			BackGroundColor.b = 255;
			BackGroundColor.a = 0;
		}
		else if(c == BLACK)
		{
			BackGroundColor.r = 0;
			BackGroundColor.g = 0;
			BackGroundColor.b = 0;
			BackGroundColor.a = 0;
		}
		else if(c == GREEN)
		{
			BackGroundColor.r = 0;
			BackGroundColor.g = 255;
			BackGroundColor.b = 0;
			BackGroundColor.a = 0;
		}
		else if(c == BLUE)
		{
			BackGroundColor.r = 0;
			BackGroundColor.g = 0;
			BackGroundColor.b = 255;
			BackGroundColor.a = 0;
		}
		else if(c == RED)
		{
			BackGroundColor.r = 255;
			BackGroundColor.g = 0;
			BackGroundColor.b = 0;
			BackGroundColor.a = 0;
		}
		else // DEfault RED
		{
			BackGroundColor.r = 255;
			BackGroundColor.g = 0;
			BackGroundColor.b = 0;
			BackGroundColor.a = 0;
		}
	}
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

int Game::Launch(SDL_Renderer* rend, Sound sound)
{
	DrawHead(rend);
	DrawTarget(rend);
	SDL_SetRenderDrawColor(rend, BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	SDL_RenderPresent(rend);
	
	my_timerID = SDL_AddTimer(delay, my_callbackfunc,0);
	int close = 0;
	int pause = 0;
	int pauseSet = 0;
	int lost = 0;
	int action = 0;	
	Configuration config;	
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
				if(!sound.Loaded() && config.iseffectOn())
				{
					sound.Launch(1);
				}
				score.increment();
				do{
						cible.setNewPosition(snake.getHeadX(), snake.getHeadY());	
				}while(snake.testPosition(cible.getX(), cible.getY()));
			}
			DrawTarget(rend);
		// Drow body
			DrawBody(rend);
		// Draw Background 
			SDL_SetRenderDrawColor(rend, BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
			SDL_RenderPresent(rend);		
		}
		else if(pause)
		{
			Pause(rend);
		}
		else 
		{
			if(!sound.Loaded() && config.iseffectOn())
			{
				sound.Launch(2);		
			}	
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
	SDL_SetRenderDrawColor(rend, BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	SDL_RenderPresent(rend);
}

void Game::Lost(SDL_Renderer* rend)
{
	stringstream scoreStr;
	scoreStr << score.getActual();
	scoreText.setText(Font, scoreStr.str().c_str());
	scoreText.Display(rend);
	lostText.Display(rend);
	SDL_SetRenderDrawColor(rend, BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	SDL_RenderPresent(rend);
}
