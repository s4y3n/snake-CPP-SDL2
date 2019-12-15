//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "pallette.hpp"
using namespace std;

Pallette::Pallette(int W, int H, string Element, TTF_Font* Font, Color origin) : StringS(Element.c_str(),W/10, 10, 9*W/10, 50),
	CancelB("Cancel",10,H-60,(W/2)-20,50),
	OkB("Ok",(W/2)+20,H-60,(W/2)-20,50), 
	Carre(50, 50, (W/2) - 25 ,W/2),
	Slider(10, 50, 50,70 + (W/10))
{
	Slider.setColor(WHITE);
	Carre.chargeColor(origin);
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
	Slider.setX((W-Wpk)/2);
	// Saving old color
	originCL = origin;
	newCL = origin;
}

Pallette::~Pallette()
{

}


void Pallette::Display(SDL_Renderer* rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	CancelB.Draw(rend,CancelB.getTexteSize());
	OkB.Draw(rend,CancelB.getTexteSize());
	StringS.Display(rend);
	// Square Display 
	Carre.setRectX(Carre.getX());
	Carre.setRectY(Carre.getY());
	Carre.setRectW(Carre.getW());
	Carre.setRectH(Carre.getH());
	SDL_SetRenderDrawColor(rend, Carre.getColorR(),Carre.getColorG(),Carre.getColorB(), Carre.getColorA());
	SDL_RenderFillRect(rend, Carre.getRect());	
	
	int W = w;//(w - 256)/2;
	int H = h;//(h - 300)/2;
	Color R = {255,0,0,255};
	Color Y = {255,255,0,255};
	Color G = {0,255,0,255};
	Color B = {0,0,255,255};
	

	int rt = R.r ;
	int gt = R.g;
	int bt = R.b;
	int at = R.a;
	int rs = (G.r - R.r)/s;
	int gs = (G.g - R.g)/s;
	int bs = (G.b - R.b)/s;
	int as = (G.a - R.a)/s;
	for(int z = 0; z < 4;z++)
	{
		if(z < 1)
		{
			rt = R.r ;
			gt = R.g;
			bt = R.b;
			at = R.a;
			rs = (Y.r - R.r)/s;
			gs = (Y.g - R.g)/s;
			bs = (Y.b - R.b)/s;
			as = (Y.a - R.a)/s;
		}else if(z < 2)
		{		
			rt = Y.r ;
			gt = Y.g;
			bt = Y.b;
			at = Y.a;
			rs = (G.r - Y.r)/s;
			gs = (G.g - Y.g)/s;
			bs = (G.b - Y.b)/s;
			as = (G.a - Y.a)/s;
		}else if(z < 3)
		{
			rt = G.r ;
			gt = G.g;
			bt = G.b;
			at = G.a;
			rs = (B.r - G.r)/s;
			gs = (B.g - G.g)/s;
			bs = (B.b - G.b)/s;
			as = (B.a - G.a)/s;
		}else
		{	
		 rt = B.r ;
		 gt = B.g;
		 bt = B.b;
		 at = B.a;
		 rs = (R.r - B.r)/s;
		 gs = (R.g - B.g)/s;
		 bs = (R.b - B.b)/s;
		 as = (R.a - B.a)/s;
		}
		for(int i = 0 ; i < s ; i++)
		{
				 Cell_SDL cell(1,Hpk,i+z*s,Ypk);
			Color c;
			c = {rt,gt,bt,255};
			if(c.r == Carre.getColorR() && c.g == Carre.getColorG() && c.b == Carre.getColorB())
			{
				Slider.setX(i + z*s + Xpk - 5);
			}
			cell.chargeColor(c);
			cell.setRectX(i + z*s+Xpk);
			cell.setRectY(Ypk);
			cell.setRectW(1);
			cell.setRectH(Hpk);
			SDL_SetRenderDrawColor(rend, cell.getColorR(),cell.getColorG(),cell.getColorB(), cell.getColorA());
			SDL_RenderFillRect(rend, cell.getRect());
			rt += rs;
			gt += gs;
			bt += bs;
		}
	}
	Slider.setRectX(Slider.getX());
	Slider.setRectY(Slider.getY());
	Slider.setRectW(Slider.getW());
	Slider.setRectH(Slider.getH());
	SDL_SetRenderDrawColor(rend, Slider.getColorR(),Slider.getColorG(),Slider.getColorB(), Slider.getColorA());
	SDL_RenderFillRect(rend, Slider.getRect());	
	
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderPresent(rend);
}

int Pallette::pickerclicked(int Bx, int By)
{
	int click = 0;
	if(Bx >= Xpk && Bx <= Xpk + Wpk && By >= Ypk && By <= Ypk + Hpk)
		click = 1;
	return click;
}

Color Pallette::getSelectedColor(int Bx, int By)
{
	int found = 0;
	Color R = {255,0,0,255};
	Color Y = {255,255,0,255};
	Color G = {0,255,0,255};
	Color B = {0,0,255,255};
	int rt = R.r ;
	int gt = R.g;
	int bt = R.b;
	int at = R.a;
	int rs = (G.r - R.r)/s;
	int gs = (G.g - R.g)/s;
	int bs = (G.b - R.b)/s;
	int as = (G.a - R.a)/s;
	for(int z = 0; z < 4;z++)
	{
		if(!found)
		{
		if(z < 1)
		{
			rt = R.r ;
			gt = R.g;
			bt = R.b;
			at = R.a;
			rs = (Y.r - R.r)/s;
			gs = (Y.g - R.g)/s;
			bs = (Y.b - R.b)/s;
			as = (Y.a - R.a)/s;
		}else if(z < 2)
		{		
			rt = Y.r ;
			gt = Y.g;
			bt = Y.b;
			at = Y.a;
			rs = (G.r - Y.r)/s;
			gs = (G.g - Y.g)/s;
			bs = (G.b - Y.b)/s;
			as = (G.a - Y.a)/s;
		}else if(z < 3)
		{
			rt = G.r ;
			gt = G.g;
			bt = G.b;
			at = G.a;
			rs = (B.r - G.r)/s;
			gs = (B.g - G.g)/s;
			bs = (B.b - G.b)/s;
			as = (B.a - G.a)/s;
		}else
		{	
		 rt = B.r ;
		 gt = B.g;
		 bt = B.b;
		 at = B.a;
		 rs = (R.r - B.r)/s;
		 gs = (R.g - B.g)/s;
		 bs = (R.b - B.b)/s;
		 as = (R.a - B.a)/s;
		}
		
		for(int i = 0 ; i < s ; i++)
		{
			if(Bx >= Xpk + i + z*s && Bx <= Xpk + i + z*s + 1)
			{
				newCL.r = rt;
				newCL.g = gt;
				newCL.b = bt;
				newCL.a = 255;
				Slider.setX(Xpk + i + z*s);
				found = 1;
				break;
			}
			rt += rs;
			gt += gs;
			bt += bs;
		}
		}
	}	
	Carre.chargeColor(newCL);
	return newCL;
}

int Pallette::Launch(SDL_Renderer* rend)
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
				case SDL_MOUSEBUTTONUP : 
						buttonDown = 0;
					break;
				case SDL_MOUSEMOTION :
					if(buttonDown)
					{
						x = event.motion.x;
						y = event.motion.y;
						xr = event.motion.xrel;
						yr = event.motion.yrel;
						newCL = getSelectedColor(x+xr, y+yr);
					}
					break;
			}
		}
		SDL_RenderClear(rend);
	}
	return close;
}

void Pallette::setCarreColor(Color c)
{
	Carre.chargeColor(c);
}

Color Pallette::getNewColor()
{
	return newCL;
}
