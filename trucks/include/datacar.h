#pragma once

class DataCar
{
private:
	std::string date; 
	std::string numberTruck;
	int weight;
public: 
	DataCar(std::string date, std::string numberTruck, int weight);
	std::string getDate();
	std::string getNumberTruck();
	int getWeight();
};