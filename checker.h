#pragma once
#include <string>

class Checker
{
public:
	static int getValue();
	static int getValue(std::string msg);
	static float getFLValue();
	static float getFLValue(std::string msg);
	static std::string getStrValue(std::string msg);

};

