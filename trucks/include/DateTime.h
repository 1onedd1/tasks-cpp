#pragma once

#include <string>
#include <sstream>

using namespace std;

class DateTime
{
private:
	int hour;
	int minute;
	int year;
	int month;
	int day;
public:
	DateTime() {}

	DateTime(int year, int month, int day, int hour, int minute) 
	{
		this->hour = hour;
		this->minute = minute;
		this->year = year;
		this->month = month;
		this->day = day;
	}

	int getHour() { return hour; };

	int getMinute() { return minute; };

	int getYear() { return year; };

	int getMonth() { return month; };

	int getDay() { return day; };

	string toString();
};