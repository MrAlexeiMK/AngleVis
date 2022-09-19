#pragma once

#include <msclr\marshal_cppstd.h>
#include "angle.h"
#include <iostream>
#include <string>

namespace Utils {
	std::string toStdString(System::String^ str);
	System::String^ toSystemString(std::string str);
	bool isCorrectAngle(std::string angle);
	int getSymbolCount(std::string str, char symbol);
}