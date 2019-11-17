#include "configuration.hpp"

using namespace std;

Configuration::Configuration() : configFileName("config.txt")
{
	chargeAll();
}



Configuration::~Configuration()
{

}

void Configuration::chargeDefault()
{
	backGroundColor = {0,0,0,0}; //BLACK;
	headColor = {255,0,0,0}; //RED;
	bodyColor = {0,0,255,0}; //BLUE;
	targetColor = {0,255,0,0}; // GREEN;
	configSet = 0;
}

void Configuration::chargeAll()
{
	
	fstream configFile;
	string line;
	configFile.open(configFileName.c_str());
	if(configFile.is_open())
	{
		while(getline(configFile,line))
		{
			cout << "Line = " << line << endl;
			if(line.size() > 16 && !line.compare(0,15,"backGroundColor"))
			{
				cout << "PArsing BGC" << endl;
				cout << line.substr(16) << endl;
				backGroundColor = parseColor(line.substr(16));
			}
			if(line.size() > 10 && !line.compare(0,9,"headColor"))
			{
				cout << "PArsing HC" << endl;
				cout << line.substr(9) << endl;
				headColor = parseColor(line.substr(10));
			}
			if(line.size() > 10 && !line.compare(0,9,"bodyColor"))
			{
				cout << "PArsing BC" << endl;
				cout << line.substr(10) << endl;
				bodyColor = parseColor(line.substr(10));
			}
			if(line.size() > 11 && !line.compare(0,11,"targetColor"))
			{
				cout << "PArsing TC" << endl;
				cout << line.substr(12) << endl;
				targetColor = parseColor(line.substr(12));
			}
		}
		configFile.close();
		configSet = 1;
	}
	else
	{
		chargeDefault();
		saveAll();
	}		
}

void Configuration::saveAll()
{

	ofstream configFile;
	configFile.open(configFileName.c_str());
	configFile << "backGroundColor=" << backGroundColor.r << ":" << backGroundColor.g << ":" << backGroundColor.b << ":" << backGroundColor.a << endl; 
	configFile << "headColor=" << ":" << headColor.r << ":" << headColor.g << ":" << headColor.b << ":" << headColor.a << endl; 
	configFile << "bodyColor=" << bodyColor.r << ":" << bodyColor.g << ":" << bodyColor.b << ":" << bodyColor.a << endl; 
	configFile << "targetColor=" << targetColor.r << ":" << targetColor.g << ":" << targetColor.b << ":" << targetColor.a << endl;
	configFile.close(); 
}

void Configuration::setBackGroundColor(COLOR C)
{
	backGroundColor = getColorFromCOLOR(C);
}

void Configuration::saveBackGroundColor(Color c)
{

}

Color Configuration::getBackGroundColor()
{
	if(!configSet)
	{
		backGroundColor = getColorFromCOLOR(BLACK);
	}
	return backGroundColor;
}

void Configuration::setHeadColor(COLOR C)
{
	headColor = getColorFromCOLOR(C);
}

void Configuration::saveHeadColor(Color c)
{

}

Color Configuration::getHeadColor()
{
	if(!configSet)
	{
		headColor = getColorFromCOLOR(RED);
	}
	return headColor;
}

void Configuration::setBodyColor(COLOR C)
{
	bodyColor = getColorFromCOLOR(C);
}

void Configuration::saveBodyColor(Color c)
{

}

Color Configuration::getBodyColor()
{
	if(!configSet)
	{
		bodyColor = getColorFromCOLOR(BLUE);
	}
	return bodyColor;
}

void Configuration::setTargetColor(COLOR C)
{
	targetColor = getColorFromCOLOR(C);
}

void Configuration::saveTargetColor(Color c)
{

}

Color Configuration::getTargetColor()
{
	if(!configSet)
	{
		targetColor = getColorFromCOLOR(GREEN);
	}
	return targetColor;
}

int Configuration::gotConfig()
{
	return configSet;
}

Color Configuration::getColorFromCOLOR(COLOR C)
{
	Color color;
	if(C == WHITE)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 0;
	}
	else if(C == BLACK)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
	else if(C == GREEN)
	{
		color.r = 0;
		color.g = 255;
		color.b = 0;
		color.a = 0;
	}
	else if(C == BLUE)
	{
		color.r = 0;
		color.g = 0;
		color.b = 255;
		color.a = 0;
	}
	else if(C == RED)
	{
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
	else // DEfault RED
	{
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.a = 0;
	}
	return color;
}

Color Configuration::parseColor(string colorStr)
{
	Color c;
	// need to find 3 : and parse them 
	int found1 = colorStr.find(":");
	int found2 = colorStr.find(":",found1 + 1);
	int found3 = colorStr.find(":", found2 + 1);
	//if(found1 != npos)
	//{
		
//	}
	string colorR = colorStr.substr(0,found1);
	string colorG = colorStr.substr(found1 + 1, found2 - found1 - 1);
	string colorB = colorStr.substr(found2 + 1, found3 - found2 - 1);
	string colorA = colorStr.substr(found3 + 1,std::string::npos);
	cout << "Extracted : " << endl; 
	cout << "R = " << colorR << endl;
	cout << "G = " << colorG << endl;
	cout << "B = " << colorB << endl;
	cout << "A = " << colorA << endl;
	c.r = stoi(colorR);
	c.g = stoi(colorG);
	c.b = stoi(colorB);
	c.a = stoi(colorA);
	return c;
}
