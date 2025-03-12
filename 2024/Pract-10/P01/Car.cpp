#include "Car.h"
#include "Exceptions.h"

void Car::setTires(Tire** tires)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->tires[i] = tires[i];
	}
}

Car::Car(FuelTank& fuelTank, Engine* engine, Tire* tires[4], Battery* battery, unsigned odometer, unsigned weight)
	: fuelTank(fuelTank), engine(engine), battery(battery), odometer(odometer), weight(weight)
{
	setTires(tires);
}

unsigned Car::getWeight() const
{
	return this->weight;
}

const FuelTank& Car::getFuelTank() const
{
	return this->fuelTank;
}

const Engine* Car::getEngine() const
{
	return this->engine;
}

void Car::drive(double km)
{
	if (km < 0)
		throw std::invalid_argument("Cannot travel negative distance in kilometers!");

	try
	{
		this->fuelTank.use(km);
		this->odometer += km;
	}
	catch (const insufficient_fuel_error& e)
	{
		std::cout << e.what();
		throw e;
	}
}

Car* dragRace(Car* car1, Car* car2)
{
	bool isFirstSufficient = true;
	bool isSecondSufficient = true;
	try
	{
		car1->drive(0.4);
	}
	catch (const insufficient_fuel_error& e)
	{
		isFirstSufficient = false;
	}
	try
	{
		car2->drive(0.4);
	}
	catch (const insufficient_fuel_error& e)
	{
		isSecondSufficient = false;
	}

	if (!isFirstSufficient && !isSecondSufficient)
		return nullptr;
	else if (isFirstSufficient && !isSecondSufficient)
		return car1;
	else if (!isFirstSufficient && isSecondSufficient)
		return car2;
	else
	{
		return ((car1->getWeight() / car1->getEngine()->getHorsePower() > car2->getWeight() / car2->getEngine()->getHorsePower()) 
			? car1 : car2);
	}
}
