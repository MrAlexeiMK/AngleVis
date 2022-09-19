#define _USE_MATH_DEFINES

#include "angle.h"
#include <math.h>

angle::angle(const angle& other) {
	degrees = other.degrees;
	minutes = other.minutes;
	seconds = other.seconds;
}

angle::angle(int32_t degrees, int32_t minutes, int32_t seconds) {
	apply(degrees, minutes, seconds);
}

angle::angle(double x, double y) : 
	angle(vectorToAngle(x, y)) {}

angle::angle(double radians) {
	degrees = (int32_t)(radians * 180 / M_PI);
	minutes = (int32_t)((radians * 180 / M_PI - degrees) * 60);
	seconds = (int32_t)((((radians * 180 / M_PI - degrees) * 60) - minutes) * 60);
	apply(degrees, minutes, seconds);
}

angle::angle(std::string angle) {
	parse(angle);
}

angle angle::operator+(const angle& other) {
	angle result;
	uint32_t degrees = this->degrees + other.degrees;
	uint32_t minutes = this->minutes + other.minutes;
	uint32_t seconds = this->seconds + other.seconds;
	result.apply(degrees, minutes, seconds);
	return result;
}

angle angle::operator-(const angle& other) {
	angle result;
	uint32_t degrees = this->degrees - other.degrees;
	uint32_t minutes = this->minutes - other.minutes;
	uint32_t seconds = this->seconds - other.seconds;
	result.apply(degrees, minutes, seconds);
	return result;
}

angle angle::operator*(const int& other) {
	angle result;
	uint32_t degrees = this->degrees * other;
	uint32_t minutes = this->minutes * other;
	uint32_t seconds = this->seconds * other;
	result.apply(degrees, minutes, seconds);
	return result;
}

angle angle::operator/(const int& other) {
	angle result;
	uint32_t degrees = this->degrees / other;
	uint32_t minutes = this->minutes / other;
	uint32_t seconds = this->seconds / other;
	result.apply(degrees, minutes, seconds);
	return result;
}

angle& angle::operator*=(const int& other) {
	uint32_t degrees = this->degrees * other;
	uint32_t minutes = this->minutes * other;
	uint32_t seconds = this->seconds * other;
	apply(degrees, minutes, seconds);
	return *this;
}

angle& angle::operator/=(const int& other) {
	uint32_t degrees = this->degrees / other;
	uint32_t minutes = this->minutes / other;
	uint32_t seconds = this->seconds / other;
	apply(degrees, minutes, seconds);
	return *this;
}

angle& angle::operator-=(const angle& other) {
	uint32_t degrees = this->degrees - other.degrees;
	uint32_t minutes = this->minutes - other.minutes;
	uint32_t seconds = this->seconds - other.seconds;
	apply(degrees, minutes, seconds);
	return *this;
}

angle& angle::operator+=(const angle& other) {
	uint32_t degrees = this->degrees + other.degrees;
	uint32_t minutes = this->minutes + other.minutes;
	uint32_t seconds = this->seconds + other.seconds;
	apply(degrees, minutes, seconds);
	return *this;
}

angle& angle::operator=(const angle& other) {
	degrees = other.degrees;
	minutes = other.minutes;
	seconds = other.seconds;
	return *this;
}

bool angle::operator==(const angle& other) {
	return degrees == other.degrees && minutes == other.minutes && seconds == other.seconds;
}

bool angle::operator==(const angle& other) const {
	return degrees == other.degrees && minutes == other.minutes && seconds == other.seconds;
}

bool angle::operator!=(const angle& other) {
	return !((*this) == other);
}

bool angle::operator<(const angle& other) {
	return degrees < other.degrees || (degrees == other.degrees && minutes < other.minutes) || (degrees == other.degrees && minutes == other.minutes && seconds < other.seconds);
}

bool angle::operator>(const angle& other) {
	return degrees > other.degrees || (degrees == other.degrees && minutes > other.minutes) || (degrees == other.degrees && minutes == other.minutes && seconds > other.seconds);
}

bool angle::operator<=(const angle& other) {
	return (*this) < other || (*this) == other;
}

bool angle::operator>=(const angle& other) {
	return (*this) > other || (*this) == other;
}

std::ostream& operator<< (std::ostream& out, const angle& x) {
	out << std::to_string(x.degrees) << "d" << std::to_string(x.minutes) << "m" << std::to_string(x.seconds) << "s";
	return out;
}

std::istream& operator>> (std::istream& in, angle& x) {
	std::string angle;
	in >> angle;
	x.parse(angle);
	return in;
}

double angle::toRadians() {
	return (degrees + minutes / 60.0 + seconds / 3600.0) * M_PI / 180;
}

int angle::toSeconds() {
	return seconds + minutes * 60 + degrees * 3600;
}

int angle::toMinutes() {
	return minutes + degrees * 60;
}

std::string angle::ToString() {
	return std::to_string(degrees) + "d" + std::to_string(minutes) + "m" + std::to_string(seconds) + "s";
}

std::string angle::ToString() const {
	return std::to_string(degrees) + "d" + std::to_string(minutes) + "m" + std::to_string(seconds) + "s";
}

//seconds - [0; 59]
//minutes - [0; 59]
//degrees - [0; 359]
void angle::normalize(int32_t& degrees, int32_t& minutes, int32_t& seconds) {
	if (seconds >= 60) {
		minutes += seconds / 60;
		seconds %= 60;
	}
	if (seconds < 0) {
		minutes += seconds / 60;
		seconds -= (seconds / 60) * 60;
	}
	if (seconds < 0) {
		minutes -= 1;
		seconds += 60;
	}
	
	if (minutes >= 60) {
		degrees += minutes / 60;
		minutes %= 60;
	}
	if (minutes < 0) {
		degrees += minutes / 60;
		minutes -= (minutes / 60) * 60;
	}
	if (minutes < 0) {
		degrees -= 1;
		minutes += 60;
	}
	
	if (degrees >= 360) {
		degrees %= 360;
	}
	if (degrees < 0) {
		degrees -= (degrees / 360) * 360;
	}
	if (degrees < 0) {
		degrees += 360;
	}
}

void angle::apply(int32_t degrees, int32_t minutes, int32_t seconds) {
	normalize(degrees, minutes, seconds);
	this->degrees = degrees;
	this->minutes = minutes;
	this->seconds = seconds;
}

void angle::parse(std::string angle) {
	try {
		uint32_t degrees = 0, minutes = 0, seconds = 0;

		size_t pos = angle.find('d');
		if (pos != angle.npos) {
			if (pos != 0) {
				degrees = std::stoi(angle.substr(0, pos));
			}
			angle = angle.substr(pos + 1);
		}
		pos = angle.find('m');
		if (pos != angle.npos) {
			if (pos != 0) {
				minutes = std::stoi(angle.substr(0, pos));
			}
			angle = angle.substr(pos + 1);
		}
		pos = angle.find('s');
		if (pos != angle.npos) {
			if (pos != 0) {
				seconds = std::stoi(angle.substr(0, pos));
			}
			angle = angle.substr(pos + 1);
		}
		if (angle != "") throw std::exception();
		apply(degrees, minutes, seconds);
	}
	catch (...) {
		throw std::invalid_argument("Your string input " + angle + " can't be parsed into angle");
	}
}

double angle::vectorToAngle(double x, double y) {
	double angle = atan2(y, x);
	if (angle < 0) {
		angle += 2 * M_PI;
	}
	return angle;
}