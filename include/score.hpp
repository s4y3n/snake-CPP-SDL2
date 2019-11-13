#include <iostream>
#include <fstream>
#include <string>
#ifndef SCORE_H
#define SCORE_H

class Score {
	public :
		Score(int l);
		~Score();
		void chargeBest();
		void setBest();
		int isBest();
		void increment();
		int getActual();
		void saveScore();
	private :
		int best;
		int actual;
		int displayed;
		int level;
};

#endif
