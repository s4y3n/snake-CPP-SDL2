//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include <iostream>
#include <fstream>
#include <string>
#ifndef SCORE_H
#define SCORE_H

class Score {
	public :
		Score(int l);
		~Score();
		void setLevel(int l);
		void chargeBest();
		void setBest();
		int isBest();
		void increment();
		int getActual();
		void saveScore();
		int getBest();
	private :
		int best;
		int actual;
		int displayed;
		int level;
		int level1;
		int level2;
		int level3;
};

#endif
