#include "Airplane.h"

Airplane::Airplane()
{
	cout << "Airplane constructor" << endl;
}

Airplane::~Airplane()
{
	cout << "Airplane destructor" << endl;
}

void Airplane::Drive(int distance)
{
	cout << "Drive in Airplane" << endl;
	this->distance += distance + 1000;
}
