#include "FuelTank.h"
#include "Exceptions.h"

void FuelTank::setCapacity(double liters)
{
	if (capacity < 0)
		throw std::invalid_argument("Invalid capacity!");

	this->capacity = liters;
}

FuelTank::FuelTank(double capacity)
{
	setCapacity(capacity);
	this->fuel = capacity;
}

void FuelTank::use(double liters)
{
	if (this->fuel < liters)
		throw insufficient_fuel_error("Unsufficient fuel to use");

	this->fuel -= liters;
}

void FuelTank::fill(double liters)
{
	if (liters < 0)
		throw std::invalid_argument("Invalid fuel to fill up!");

	if (this->fuel + liters >= capacity)
		this->fuel = capacity;
	else
		this->fuel += liters;
}
