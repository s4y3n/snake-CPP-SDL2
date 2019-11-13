#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#ifndef TEXT_H
#define TEXT_H
using namespace std;

class Text{
	public :
		Text(string t, int X, int Y, int W, int H);
		Text(const Text &t);
		~Text();
		void Free();
		void Init(TTF_Font* Font);
		void setText(TTF_Font* Font, string s);
		void Display(SDL_Renderer* rend);
		void setX(int X);
		int getX();
		void setY(int Y);
		int getY();
		void setW(int W);
		int getW();
		void setH(int H);
		int getH();
		SDL_Rect* getRect();
	private :
		string textStr;
		SDL_Surface *text ;
		SDL_Color textColor;
		SDL_Texture* textMessage;
		SDL_Rect textPosition ;
};

#endif
