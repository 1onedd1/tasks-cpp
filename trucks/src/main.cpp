// taskscpp.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "fstream"
#include <vector>
#include <string>
#include "datacar.h"

#include "main.h"

//std::vector<DataCar> CAR_LIST;
//
int main()
{
	std::ifstream table("E:\\Personal\\tasks\\cpp\\table.txt");

	std::string input = "";

	while (std::getline(table, input)) {
		if (input._Equal("")) {
			continue;
		}

		std::vector<std::string> infoCar = splitString(input, ", ");
		
		std::string suffix = ".txt";
		std::fstream fs;

		if (fs.good()) {
			fs.open(infoCar.at(1) + suffix, std::fstream::app);
			fs << input << std::endl;
		}
		else {
			fs.open(infoCar.at(1) + ".txt");
			fs << input;
		}

		fs.close();
	}

	table.close();

	return 0;
}

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