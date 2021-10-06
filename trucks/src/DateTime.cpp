#include <string>
#include <sstream>

#include "DateTime.h"

string DateTime::toString()
{
	stringstream ss;
	ss << year << "." << month << "." << day << " " << hour << ":" << minute;
	return ss.str();
}

