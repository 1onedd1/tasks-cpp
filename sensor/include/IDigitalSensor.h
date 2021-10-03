#include "ISensor.h"

class IDigitalSensor : public ISensor {
protected:
	bool hasPower;

public:
	virtual void powerOn() = 0;

	virtual void powerOff() = 0;

	virtual bool isPower() = 0;

	virtual void display() = 0;
};