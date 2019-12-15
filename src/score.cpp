//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include "score.hpp"



using namespace std;

Score::Score(int l)
{
	level1 = 0;
	level2 = 0;
	level3 = 0;
	setLevel(l);
}

Score::~Score()
{
	

}

void Score::setLevel(int l)
{
	actual = 0;
	displayed = 0;
	level = l;
	chargeBest();
}

void Score::chargeBest()
{
	fstream scoreFile;
	string line; 
	scoreFile.open("score.txt");
	int reads = 0;
	if(scoreFile.is_open())
	{
		/*
		while(reads < level)
		{
			getline(scoreFile,line);
			reads++;
		}
		string sc = line.substr(7); //score1=, score2=,...
		cout << "score of level " << level << "="  << sc << endl;
		// TEMPORATY
		best = std::stoi(sc);
		*/
		while(getline(scoreFile,line))
		{
			if(line.compare(0,6,"score1") == 0 )
			{
				level1 = std::stoi(line.substr(7));
				if(level == 1)
				{
					best = level1;
				}
			}else if(line.compare(0,6,"score2") == 0)
			{
				level2 = std::stoi(line.substr(7));
				if(level == 2)
				{
					best = level2;
				}
			}else if(line.compare(0,6,"score3") == 0)
			{
				level3 = std::stoi(line.substr(7));
				if(level == 3)
				{
					best = level3;
				}
			}
		}
		scoreFile.close();
	}
	else
	{
		cout << "Enable to open file : charge best score" << endl;
		ofstream scoreFile2;
		scoreFile2.open("score.txt");
		/*for(int i = 0 ; i < 3; i++)
		{
			scoreFile2 << "score" << i + 1 << "=0" << endl;
		}*/
		scoreFile2 << "score1=" << level1 << endl;
		scoreFile2 << "score2=" << level2 << endl;
		scoreFile2 << "score3=" << level3 << endl;
		scoreFile2.close();
	//	cout << "Enable to open file " << endl;
		best = 0;
	} 	

}

void Score::setBest()
{
	best = actual;
}

int Score::isBest()
{
	return (actual > best);
}

void Score::increment()
{
	actual++;
	if(isBest())
	{
		saveScore();
	}
}

int Score::getActual()
{
	return actual;
}

void Score::saveScore()
{
	cout << "Saving best score !! " << endl;
	fstream scoreFile;
	string line; 
	scoreFile.open("score.txt");
	int reads = 0;
	best = actual;
	switch(level)
	{
		case 1 :
			level1 = best;
			break;
		case 2 :
			level2 = best;
			break;
		case 3 : 
			level3 = best;
			break;
	}
	scoreFile << "score1=" << level1 << endl;
	scoreFile << "score2=" << level2 << endl;
	scoreFile << "score3=" << level3 << endl;
	scoreFile.close();
	/*
	if(scoreFile.is_open())
	{
		while(reads < level - 1)
		{
			getline(scoreFile,line);
			reads++;
		}
		line = "score" + to_string(level) + "=" + to_string(actual);
		best = actual;
		scoreFile << line << endl;
		scoreFile.close();
	}
	else
	{
		cout << "Enable to open file : new best score " << endl;
		ofstream scoreFile2;
		scoreFile2.open("score.txt");
		for(int i = 0 ; i < 3; i++)
		{
			if(level != i + 1)
			{
				scoreFile2 << "score" << i + 1 << "=0" << endl;
			}
			else
			{
				line = "score" + to_string(level) + "=" + to_string(actual);
				scoreFile2 << line << endl;
			}

		}
		scoreFile2.close();
		//cout << "Enable to open file " << endl;
		best = actual;
	}
	*/ 
}

int Score::getBest()
{
	return best;
}	
