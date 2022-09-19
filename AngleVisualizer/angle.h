#pragma once

#include <iostream>
#include <string>

class angle {
public:
	uint16_t degrees;
	uint16_t minutes;
	uint16_t seconds;

	angle(const angle&);
	angle(int32_t degrees = 0, int32_t minutes = 0, int32_t seconds = 0);
	angle(double x, double y);
	angle(double radians);
	angle(std::string angle);

	angle operator+(const angle& other);
	angle operator-(const angle& other);
	angle operator*(const int& other);
	angle operator/(const int& other);

	angle& operator*=(const int& other);
	angle& operator/=(const int& other);
	angle& operator-=(const angle& other);
	angle& operator+=(const angle& other);
	angle& operator=(const angle& other);

	bool operator==(const angle& other);
	bool operator==(const angle& other) const;
	bool operator>=(const angle& other);
	bool operator<=(const angle& other);
	bool operator>(const angle& other);
	bool operator<(const angle& other);
	bool operator!=(const angle& other);

	friend std::ostream& operator<< (std::ostream& out, const angle& x);
	friend std::istream& operator>> (std::istream& in, angle& x);

	double toRadians();
	int toSeconds();
	int toMinutes();

	std::string ToString();
	std::string ToString() const;
private:
	void apply(int32_t degrees = 0, int32_t minutes = 0, int32_t seconds = 0);
	void normalize(int32_t& degrees, int32_t& minutes, int32_t& seconds);
	void parse(std::string angle);
	double vectorToAngle(double x, double y);
};