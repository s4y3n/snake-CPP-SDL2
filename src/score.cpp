#include "score.hpp"



using namespace std;

Score::Score(int l)
{
	actual = 0;
	displayed = 0;
	level = l;
	chargeBest();
}

Score::~Score()
{
	

}

void Score::chargeBest()
{
	fstream scoreFile;
	string line; 
	scoreFile.open("score.txt");
	int reads = 0;
	if(scoreFile.is_open())
	{
		while(reads < level)
		{
			getline(scoreFile,line);
			reads++;
		}
		string sc = line.substr(7); //score1=, score2=,...
		cout << "score of level " << level << "="  << sc << endl;
		// TEMPORATY
		best = std::stoi(sc);
		scoreFile.close();
	}
	else
	{
		cout << "Enable to open file " << endl;
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
		cout << "Enable to open file " << endl;
		best = actual;
	} 
}	
