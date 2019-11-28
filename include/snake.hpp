//#include <SDL2/SDL.h>
#include <SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL_image.h>
//#include <SDL2/SDL_timer.h>
#include <SDL_timer.h>
#include <iostream>
#include <vector>
#include "functions.hpp"
#include "cell.hpp"
#include "head.hpp"
#include "body.hpp" 
#include "cible.hpp"
#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {
	public :
		Snake(int W, int H, int X, int Y);
		~Snake();
		void setLimits(int XMAX, int YMAX);
		void createBody(int i);
		void createBodyElement();
		void move();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
		void moveBody();
		int getHeadColor(int e);
		int getBodyColor(int e);
		SDL_Rect* getHeadRect();
		int getHeadX();
		int getHeadY();
		int targetReached(Cible c);
		void addTarget(Cible c);
		int getBodyCount();
		SDL_Rect* getBodyAt(int pos);
		void setDirection(DIRECTIONS d);
		void getStatus();
		int targetOutOfBody();
		int contact();
		int testPosition(int x,int y);
		void DrawHead(SDL_Renderer* rend);
		void DrawBody(SDL_Renderer* rend);
	private :
		Head head;
		vector<Body> body;
		vector<Cible> targets;
		int bodyLength;
		int limitX;
		int limitY;
		SDL_Color bodyColor;
		SDL_Color bodyColor2;
};

#endif //SNAKE_H
