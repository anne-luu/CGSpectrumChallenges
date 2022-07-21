#include "Boat.h"

void Boat::Drive(int distance)
{
	cout << "Drive in Boat Class" << endl;
	this->distance += distance + 15;
}
