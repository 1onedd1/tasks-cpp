#pragma once

class CarManager {
private:
	std::vector<DataCar> CAR_LIST;
public:
	int sumWeight(std::vector<DataCar>& list);

	void push_back(DataCar car) { CAR_LIST.push_back(car); }

	void pop_back() { CAR_LIST.pop_back(); }
};