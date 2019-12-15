//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "bestscores.hpp"
#include "score.hpp"
#include <iostream>
#include <sstream> 

using namespace std;

BestScores::BestScores(int x, int y,TTF_Font* Font) : mainWindow(x,y),
	headS("BEST SCORES :", 50, y/4 - 40, x-100, 80),
	scoreLevel1S("Level 1 : ", 50, y/4 - 40, x-100, 80),
	scoreLevel2S("Level 2 : ", 50, y/4 - 40, x-100, 80),
	scoreLevel3S("Level 3 : ", 50, y/4 - 40, x-100, 80),
	backB("BACK", 50, y/4 - 40, x-100, 80)
{
	stringstream scoreStr;

	headS.Init(Font);
	headS.setUnclickable();

	Score scorel(1);
	scoreLevel1S.Init(Font);
	scoreStr << "Level 1 : " << scorel.getBest();
	scoreLevel1S.setText(Font, scoreStr.str().c_str());
	scoreLevel1S.setUnclickable();
	
	scoreStr.str("");
	scorel.setLevel(2);		
	scoreLevel2S.Init(Font);
	scoreStr << "Level 2 : " << scorel.getBest();
	scoreLevel2S.setText(Font, scoreStr.str().c_str());
	scoreLevel2S.setUnclickable();

	scoreStr.str("");	
	scorel.setLevel(3);
	scoreLevel3S.Init(Font);
	scoreStr << "Level 3 : " << scorel.getBest();
	scoreLevel3S.setText(Font, scoreStr.str().c_str());
	scoreLevel3S.setUnclickable();

	backB.Init(Font);
	mainWindow.addButton(headS);
	mainWindow.addButton(scoreLevel1S);
	mainWindow.addButton(scoreLevel2S);
	mainWindow.addButton(scoreLevel3S);
	mainWindow.addButton(backB);
}


BestScores::~BestScores()
{
	headS.Free();
	scoreLevel1S.Free();
	scoreLevel2S.Free();
	scoreLevel3S.Free();
	backB.Free();
}

int BestScores::Launch(SDL_Renderer* rend)
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
		if(launch != 0 && launch != 5)
		{
			cout << "Launch value = " << launch << endl;
			switch(launch)
			{
				case 1 :
						cout << "Clicked on string ! " << endl;
						break;
				case 2:
					cout << "BestScores background" << endl;
					break;
				case 3:
					cout << "BestScores Head" << endl;
					break;
				case 4:
					cout << "BestScores Body" << endl;
					break;
				case 5:
					cout << "BestScores Targets" << endl;
					break;
			}
			launch = 0;
		}else if(launch == 5)
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

void BestScores::DisplayMainWindow(SDL_Renderer* rend)
{
	mainWindow.Display(rend);
}
