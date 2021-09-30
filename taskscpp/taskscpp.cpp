// taskscpp.cpp: определяет точку входа для приложения.
//

#include "taskscpp.h"
#include "fstream"
#include <vector>
#include <string>

int main()
{
	std::ifstream table ("E:\\Personal\\tasks\\cpp\\table.txt");

	std::vector<std::string> lines;
	std::string inputDate = "";
	std::string input = "";
	std::string inputDates = "";

	while (std::getline(table, input)) {
		lines.push_back(input);
	}

	for (std::string item : lines) {
		std::cout << item << std::endl;
	}

	std::cout << "Hello CMake." << std::endl;
	return 0;
}


