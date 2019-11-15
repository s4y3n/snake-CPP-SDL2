#include "text.hpp"


#ifndef BUTTON_H
#define BUTTON_H
using namespace std;

class Button : public Text {
	public :
		Button(string t, int X, int Y, int W, int H);
		Button(const Button &b);
		~Button();
		int isClicked(int x, int y);
		void Draw(SDL_Renderer* rend, int Max);
		void show();
		void setUnclickable();
	private :
		int clickable ;
};

#endif
