#include "Car.h"

void Car::Drive(int distance)
{
	cout << "Drive in Car Class" << endl;
	this->distance += distance + 100;
}
