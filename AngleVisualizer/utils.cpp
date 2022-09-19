#define _USE_MATH_DEFINES

#include "utils.h"
#include <cmath>

namespace Utils {
	std::string toStdString(System::String^ str) {
		return msclr::interop::marshal_as<std::string>(str);
	}

	System::String^ toSystemString(std::string str) {
		return gcnew System::String(str.c_str());
	}

	bool isCorrectAngle(std::string ang) {
		if (getSymbolCount(ang, 'd') > 1 || getSymbolCount(ang, 'm') > 1 || getSymbolCount(ang, 's') > 1) {
			return false;
		}
		try {
			angle a(ang);
		}
		catch (...) {
			return false;
		}
		return true;
	}

	int getSymbolCount(std::string str, char symbol) {
		int count = 0;
		for (size_t i = 0; i < str.length(); ++i) {
			if (str[i] == symbol) {
				count++;
			}
		}
		return count;
	}
}