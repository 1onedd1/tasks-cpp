#include "ISensor.h"

class PressureSensor : public Sensor {
private:
	void update() override
	{
		for (;;) {
			//some computed
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
};
