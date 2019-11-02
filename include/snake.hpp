#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
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
		void move();
		void moveUp();
		void moveDown();
		void moveRight();
		void moveLeft();
		void moveBody();
		int getHeadColorR();
		int getHeadColorG();
		int getHeadColorB();
		int getHeadColorA();
		SDL_Rect* getHeadRect();
		int getHeadX();
		int getHeadY();
		int targetReached(Cible c);
		void addTarget(Cible c);
		int getBodyCount();
		SDL_Rect* getBodyAt(int pos);
		void setDirection(DIRECTIONS d);
	private :
		Head head;
		vector<Body> body;
		vector<Cible> targets;
		int bodyLength;
		int limitX;
		int limitY;
};

#endif //SNAKE_H
