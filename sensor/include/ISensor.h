#include <iostream>
#include <string>

using namespace std;

class ISensor {
private:
	// for inside computation
	void virtual update() = 0;

protected:
	string type;
	float value;

public:
	virtual float getValue() = 0;

	virtual string getType() = 0;
};