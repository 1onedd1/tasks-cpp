#include "IDigitalSensor.h"
#include "windows.h"

class PressureSensor : public IDigitalSensor 
{
private:
	void update() override
	{
		for (;;) {
			if (!hasPower) break;

			//some computation
			value = value + 1;

			if (value == 10)
			{
				value = 0;
			}

			display();
			Sleep(1);
		}
	}
public:
	PressureSensor(string type) {
		this->type = type;
		this->value = 0;
	}

	float getValue() override
	{
		return this->value;
	}

	string getType() override 
	{
		return this->type;
	}

	void powerOn() override
	{
		this->update();
		hasPower = true;
	}

	void powerOff() override
	{
		hasPower = false;
	}

	bool isPower() override
	{
		return hasPower;
	}

	void display() override
	{
		cout << value;
	}
};
