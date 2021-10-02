#include <string>

#include "datacar.h"

DataCar::DataCar(std::string date, std::string numberTruck, int weight)
{
	this->date = date;
	this->numberTruck = numberTruck;
	this->weight = weight;
};

std::string DataCar::getDate() 
{
	return date;
}

std::string DataCar::getNumberTruck()
{
	return numberTruck;
}

int DataCar::getWeight()
{
	return weight;
}

