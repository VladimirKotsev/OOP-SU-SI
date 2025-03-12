#pragma once
#include <iostream>

class FuelTank
{
private:
	double fuel = 0;
	double capacity = 0;

	void setCapacity(double liters);

public:
	FuelTank(double capacity);

	void use(double liters);
	void fill(double liters);
};

