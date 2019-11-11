#include "button.hpp"

Button::Button(string t, int X, int Y, int W, int H) :
		Text(t, X, Y, W, H)
{
	clicked = 0;
}

Button::~Button()
{


}

void Button::Draw(SDL_Renderer* rend)
{
	Display(rend);
	SDL_SetRenderDrawColor(rend, 255,255,255,255);
	SDL_RenderDrawRect(rend, getRect());	

}


int Button::isClicked(int x, int y)
{
	if(x >= getX() && x <= getX() + getW() && y >= getY() && y <= getY() + getH())
		clicked = 1;

	return clicked;
}
