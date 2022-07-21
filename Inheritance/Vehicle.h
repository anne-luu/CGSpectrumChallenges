#pragma once

#include<iostream>

using namespace std;

class Vehicle
{
protected:
	int distance;

public:
	Vehicle();
	virtual ~Vehicle();
	virtual void Drive(int distance);

	//Pure Virtual function which makes Vehicle an abstract class
	// Abstract classes cannot be instantiated
	//virtual void vfDrive(int distance) = 0;

	//Getters and Setters
	void setDistance(int distance);
	int getDistance();
};

