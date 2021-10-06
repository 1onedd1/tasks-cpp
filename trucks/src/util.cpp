#include <string>
#include <vector>

#include "util.h"

std::vector<std::string> splitString(std::string string, std::string delimeter)
{
	size_t pos = 0;
	std::string token;
	std::vector<std::string> vec;

	while ((pos = string.find(delimeter)) != std::string::npos) {
		token = string.substr(0, pos);
		vec.push_back(token);
		string.erase(0, pos + delimeter.length());
	};

	vec.push_back(string);

	return vec;
}