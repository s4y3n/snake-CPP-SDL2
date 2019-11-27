#include "bgcolor.hpp"
using namespace std;

BgColor::BgColor(int W, int H, string Element, TTF_Font* Font, Color origin) : StringS(Element.c_str(),W/10, 10, 9*W/10, 50),
	CancelB("Cancel",10,H-60,(W/2)-20,50),
	OkB("Ok",(W/2)+20,H-60,(W/2)-20,50), 
	BlackChoice(50, 50, (W/2) - 25 - 50 ,W/2),
	WhiteChoice(50, 50, (W/2) + 25,W/2),
	Rect(W,100,0,(W/2) - 25)
{
	Rect.setColor(GREEN);
	WhiteChoice.setColor(WHITE);
	BlackChoice.setColor(BLACK);
	StringS.Init(Font);
	StringS.setUnclickable();
	CancelB.Init(Font);
	OkB.Init(Font);
	w = W;
	h = H;
	s = 50;
	Wpk = 4*s;
	Hpk = 50;
	Xpk = (W-Wpk)/2;
	Ypk = (W/10) + 50 + 20 ;
//	BlackChoice.setY((W+Wpk)/2);
//	WhiteChoice.setX((W-Wpk)/2);
	// Saving old color
	originCL = origin;
	newCL = origin;
}

BgColor::~BgColor()
{

}


void BgColor::Display(SDL_Renderer* rend)
{
	Cell_SDL Choice(50, 50, (w/2) + 25,w/2);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	CancelB.Draw(rend,CancelB.getTexteSize());
	OkB.Draw(rend,CancelB.getTexteSize());
	StringS.Display(rend);
	Rect.setRectX(Rect.getX());
	Rect.setRectY(Rect.getY());
	Rect.setRectW(Rect.getW());
	Rect.setRectH(Rect.getH());
	SDL_SetRenderDrawColor(rend, Rect.getColorR(),Rect.getColorG(),Rect.getColorB(), Rect.getColorA());
	SDL_RenderFillRect(rend, Rect.getRect());	

	// Square Display 
	BlackChoice.setRectX(BlackChoice.getX());
	BlackChoice.setRectY(BlackChoice.getY());
	BlackChoice.setRectW(BlackChoice.getW());
	BlackChoice.setRectH(BlackChoice.getH());
	SDL_SetRenderDrawColor(rend, BlackChoice.getColorR(),BlackChoice.getColorG(),BlackChoice.getColorB(), BlackChoice.getColorA());
	SDL_RenderFillRect(rend, BlackChoice.getRect());	
	WhiteChoice.setRectX(WhiteChoice.getX());
	WhiteChoice.setRectY(WhiteChoice.getY());
	WhiteChoice.setRectW(WhiteChoice.getW());
	WhiteChoice.setRectH(WhiteChoice.getH());
	SDL_SetRenderDrawColor(rend, WhiteChoice.getColorR(),WhiteChoice.getColorG(),WhiteChoice.getColorB(), WhiteChoice.getColorA());
	SDL_RenderFillRect(rend, WhiteChoice.getRect());	
	if(compareColors(newCL, BlackChoice.getCOLOR()))
	{
		Choice.setRectX(BlackChoice.getX());
		Choice.setRectY(BlackChoice.getY());
		Choice.setRectW(BlackChoice.getW());
		Choice.setRectH(BlackChoice.getH());
		Choice.chargeColor(WhiteChoice.getCOLOR());
	}else
	{
		Choice.setRectX(WhiteChoice.getX());
		Choice.setRectY(WhiteChoice.getY());
		Choice.setRectW(WhiteChoice.getW());
		Choice.setRectH(WhiteChoice.getH());
		Choice.chargeColor(BlackChoice.getCOLOR());
	}
	SDL_SetRenderDrawColor(rend, Choice.getColorR(),Choice.getColorG(),Choice.getColorB(), Choice.getColorA());
	SDL_RenderDrawRect(rend, Choice.getRect());	
	
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}

int BgColor::pickerclicked(int Bx, int By)
{
	int click = 0;
	if(BlackChoice.clicked(Bx,By) || WhiteChoice.clicked(Bx,By))
		click = 1;
	return click;
}

Color BgColor::getSelectedColor(int Bx, int By)
{
	int found = 0;
	if(BlackChoice.clicked(Bx,By))
	{
		newCL = BlackChoice.getCOLOR();
	}
	else
	{
		newCL = WhiteChoice.getCOLOR();
	}
	return newCL;
}

int BgColor::Launch(SDL_Renderer* rend)
{
	int close = 0;
	int choice = 0;
	int buttonDown = 0;
	int x = 0;
	int y = 0;
	int yr = 0;
	int xr = 0;
	while(!close && !choice)
	{
		Display(rend);
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
						// event.button.x, event.button.y
						x = event.button.x;
						y = event.button.y;
						if(pickerclicked(x,y))
						{
							buttonDown = 1;
							newCL = getSelectedColor(x,y);
						}
						else if(OkB.isClicked(x,y))
							{
								// nothing to do
								choice = 1; 
							}else if(CancelB.isClicked(x,y)) // Cancel 
							{
								choice = 1;
								newCL = originCL;
							}
					break;	
			}
		}
		SDL_RenderClear(rend);
	}
	return close;
}

void BgColor::setBlackChoiceColor(Color c)
{
	BlackChoice.chargeColor(c);
}

Color BgColor::getNewColor()
{
	return newCL;
}
