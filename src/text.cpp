#include "text.hpp"

Text::Text(string t, int X, int Y, int W, int H)
{
	textStr = t;
	text = NULL;
	textColor = {0,255,0};
	textPosition.x = X;
	textPosition.y = Y;
	textPosition.w = W;
	textPosition.h = H;
}


Text::~Text()
{
//	if(text != NULL)
//		SDL_FreeSurface(text);
//	if(textMessage != NULL)
//		SDL_DestroyTexture(textMessage);
}

void Text::Free()
{
	if(text != NULL)
		SDL_FreeSurface(text);
}

void Text::Init(TTF_Font* Font )
{
	text = TTF_RenderText_Solid(Font, textStr.c_str(), textColor);
}

void Text::setText(TTF_Font* Font, string s)
{
	textStr = s;
	text = TTF_RenderText_Solid(Font, textStr.c_str(), textColor);
}

void Text::Display(SDL_Renderer* rend)
{
	textMessage = SDL_CreateTextureFromSurface(rend,text);
	SDL_RenderCopy(rend,textMessage,NULL,&textPosition);
}

int Text::getX()
{
	return textPosition.x;
}
int Text::getY()
{
	return textPosition.y;
}
int Text::getW()
{
	return textPosition.w;
}
int Text::getH()
{
	return textPosition.h;
}

SDL_Rect* Text::getRect()
{
	return &textPosition;
}
