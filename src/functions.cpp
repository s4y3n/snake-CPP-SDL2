#include "functions.hpp"


using namespace std;

void up()
{
	if(DEBUG)
		cout << "UP" << endl;
}

void down()
{
	if(DEBUG)
		cout << "DOWN" << endl;
}

void right()
{
	if(DEBUG)
		cout << "RIGHT" << endl;
}

void left()
{
	if(DEBUG)
		cout << "LEFT" << endl;
}

int compareColors(Color c1, Color c2)
{
	int same = 0;
	if(c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a)
		same = 1;
	return same;
}

