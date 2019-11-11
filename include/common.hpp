#ifndef COMMON_H
#define COMMON_H

enum COLOR {BLACK, WHITE, RED, BLUE, GREEN};
enum DIRECTIONS {IDLE, UP, DOWN, LEFT, RIGHT};
typedef struct color {
	int r;
	int g;
	int b;
	int a;
}Color;

#endif
