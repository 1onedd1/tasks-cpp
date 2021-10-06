#pragma once

#include <string>
#include "DateTime.h"

class DataCar
{
private:
	DateTime date;
	std::string numberTruck;
	int weight;
public:
	DataCar(DateTime date, std::string numberTruck, int weight) 
		: date(date), numberTruck(numberTruck), weight(weight) {};
	DateTime getDate() { return date; };
	std::string getNumberTruck() { return numberTruck; };
	int getWeight() { return weight; };
};