//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include <iostream>
#include "common.hpp"
#ifndef FUNCTIONS_H
#define FUNCTION_H

#define DEBUG 0

#define SIZEX 400
#define SIZEY 400
#define RECW SIZEX/20
#define RECH SIZEY/20


void up();
void down();
void right();
void left();

int compareColors(Color c1, Color c2);

#endif

