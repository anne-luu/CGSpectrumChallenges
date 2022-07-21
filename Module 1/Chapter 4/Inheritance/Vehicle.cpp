#include "Vehicle.h"

Vehicle::Vehicle()
	:distance(0)
{
	cout << "Vehicle Constructor" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle Destructor" << endl;
}

void Vehicle::Drive(int distance)
{
	cout << "Drive in Vehicle Class" << endl;
	this->distance += distance;
}

void Vehicle::setDistance(int distance)
{
	this->distance = distance;
}

int Vehicle::getDistance()
{
	return distance;
}
