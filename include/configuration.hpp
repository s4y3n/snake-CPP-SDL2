//Project : Snake
//Writer : Yahya LBARNOUSSI
//Mail : yahya.lbarnoussi@gmail.com
//Date : 15-12-2019

#include <iostream>
#include <fstream>
#include <string>
#include "common.hpp"

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
using namespace std;
class Configuration {
	public :
		Configuration();
		~Configuration();
		void chargeAll();
		void chargeDefault();
		void saveAll();
		void setBackGroundColor(COLOR C);
		void saveBackGroundColor(Color c);
		Color getBackGroundColor();
		void setHeadColor(COLOR C);
		void saveHeadColor(Color c);
		Color getHeadColor();
		void setBodyColor(COLOR C);
		void saveBodyColor(Color c);
		Color getBodyColor();
		void setTargetColor(COLOR C);
		void saveTargetColor(Color c);
		Color getTargetColor();
		int gotConfig();
		Color getColorFromCOLOR(COLOR C);
		Color parseColor(string colorStr);
		int ismusicOn(void);
		int iseffectOn(void);
	private :
		int configSet;
		Color backGroundColor;
		Color headColor;
		Color bodyColor;
		Color targetColor;
		int musicOn;
		int effectOn;
		string configFileName;
};

#endif
