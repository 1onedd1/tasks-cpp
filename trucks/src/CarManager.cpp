#include <string>
#include <vector>

#include "DataCar.h"
#include "CarManager.h"

int CarManager::sumWeight(std::vector<DataCar>& list)
{
	int result = 0;

	for (DataCar car : list)
	{
		result += car.getWeight();
	}

	return result;
}