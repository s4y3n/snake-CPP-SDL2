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
	private :
		int configSet;
		Color backGroundColor;
		Color headColor;
		Color bodyColor;
		Color targetColor;
		string configFileName;
};

#endif
