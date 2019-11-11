#include "eye.hpp"

using namespace std;

Eye::Eye(int W, int H, int X, int Y):Cell_SDL(W,H,X,Y)
{
	setColor(WHITE);
}

Eye::~Eye()
{

}

void Eye::Draw(SDL_Renderer* rend)
{
	setRectX(getX());
	setRectY(getY());
	setRectW(getW());
	setRectH(getH());
	SDL_SetRenderDrawColor(rend, getColorR(),getColorG(),getColorB(), getColorA());
	SDL_RenderFillRect(rend, getRect());	
}
