#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>

#include "main.h" 
#include "DateTime.h"
#include "datacar.h"
#include "util.h"
#include "CarManager.h"

void sort_vectorOfDataCar(std::vector<DataCar>& vector);
DateTime parse_DateTime(std::string dt);
void writeToFile(std::string string, std::string file_path);
void prepare_folder();

int main()
{
	std::vector<DataCar> CAR_LIST;

	std::ifstream table("./resources/table.txt");
	std::string input;

	while (std::getline(table, input)) {
		if (input._Equal("")) {
			continue;
		}

		std::vector<std::string> infoCar = splitString(input, ", ");

		DateTime dt = parse_DateTime(infoCar.at(0));
		int weight = std::stoi(infoCar.at(2));

		DataCar dc(dt, infoCar.at(1), weight);
		CAR_LIST.push_back(dc);
	}

	table.close();

	sort_vectorOfDataCar(CAR_LIST);

	prepare_folder(); 

	int sumWeight = 0;
	for (int i = 1; i < CAR_LIST.size(); i++)
	{
		DataCar car1 = CAR_LIST.at(i - 1);
		DataCar car2 = CAR_LIST.at(i);

		sumWeight += car1.getWeight();

		DateTime dt = car1.getDate();
		std::string truck = car1.getNumberTruck();

		std::ostringstream out_string;
		out_string << dt.getHour() << "." << dt.getMinute() << " " << dt.getDay() << "." << dt.getMonth() << 
			"." << dt.getYear() << ", " << truck << ", " << car1.getWeight() << std::endl;

		std::stringstream ss_path;
		ss_path << "./trucksdata/" << truck << ".txt";

		writeToFile(out_string.str(), ss_path.str());

		if (!(truck._Equal(car2.getNumberTruck())) || CAR_LIST.size() == i + 1)
		{
			CarManager cm;
			std::stringstream ss_total;
			ss_total << "total weight: " << sumWeight;
			sumWeight = 0;
			writeToFile(ss_total.str(), ss_path.str());
		}
	}

	return 0;
}

void writeToFile(std::string string, std::string file_path)
{
	std::fstream fs;

	fs.open(file_path, std::fstream::app);

	if (fs.is_open())
	{
		fs << string;
	}

	fs.close();
}

//delete folder and files and create new folder if it doesn't exists
void prepare_folder()
{
	if (std::filesystem::exists("trucksdata"))
	{
		for (auto entry : std::filesystem::directory_iterator("./trucksdata/"))
		{
			std::filesystem::remove(entry);
		}
	}
	else
	{
		std::filesystem::create_directory("trucksdata");
	}
}

DateTime parse_DateTime(std::string dt)
{
	std::vector<std::string> date_time = splitString(dt, " ");

	std::string date = date_time.at(0);
	std::string time = date_time.at(1);

	std::vector<std::string> pdate = splitString(date, ".");
	std::vector<std::string> ptime = splitString(time, ":");

	int year = std::stoi(pdate.at(0));
	int month = std::stoi(pdate.at(1));
	int day = std::stoi(pdate.at(2));

	int hour = std::stoi(ptime.at(0));
	int minute = std::stoi(ptime.at(1));

	return DateTime(day, month, year, hour, minute);
}

void sort_vectorOfDataCar(std::vector<DataCar>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		for (int j = i; j < vector.size(); j++)
		{
			DataCar car1 = vector.at(j);
			DataCar car2 = vector.at(i);

			DateTime dt1 = car1.getDate();
			DateTime dt2 = car2.getDate();
			if(car1.getNumberTruck() > car2.getNumberTruck())
			{ 
				std::swap(vector[j], vector[i]);
			}
			else if (car1.getNumberTruck() == car2.getNumberTruck() && dt1.getYear() > dt2.getYear())
			{
				std::swap(vector[j], vector[i]);
			}
			else if (car1.getNumberTruck() == car2.getNumberTruck() && dt1.getYear() == dt2.getYear() && 
				dt1.getMonth() > dt2.getMonth())
			{
				std::swap(vector[j], vector[i]);
			}
			else if (car1.getNumberTruck() == car2.getNumberTruck() && dt1.getYear() == dt2.getYear() && 
				dt1.getMonth() == dt2.getMonth() && dt1.getDay() > dt2.getDay())
			{
				std::swap(vector[j], vector[i]);
			}
			else if (car1.getNumberTruck() == car2.getNumberTruck() && dt1.getYear() == dt2.getYear() && 
				dt1.getMonth() == dt2.getMonth() && dt1.getDay() == dt2.getDay() && dt1.getHour() > dt2.getHour())
			{
				std::swap(vector[j], vector[i]);
			}
			else if (car1.getNumberTruck() == car2.getNumberTruck() && dt1.getYear() == dt2.getYear() && 
				dt1.getMonth() == dt2.getMonth() && dt1.getDay() == dt2.getDay() && dt1.getHour() == dt2.getHour() && 
				dt1.getMinute() > dt2.getMinute())
			{
				std::swap(vector[j], vector[i]);
			}
		}
	}
}
