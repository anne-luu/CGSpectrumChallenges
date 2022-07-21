#pragma once
#include "Vehicle.h"
class Airplane : virtual public Vehicle
{
public:
	Airplane();
	virtual ~Airplane();

	void Drive(int distance) override;
};

