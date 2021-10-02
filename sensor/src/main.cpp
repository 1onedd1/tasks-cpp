#include <iostream>
#include <string>
#include "PressureSensor.cpp"


#include "main.h"
using namespace std;

int main() {
	PressureSensor ps("Pressure");

	cout << "Sensor value = " << ps.getValue() << endl;
	cout << "Sensor type = " << ps.getType() << endl;
}