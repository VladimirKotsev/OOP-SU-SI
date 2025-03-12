#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tire.h"
#include "Battery.h"

class Car
{
private:
	FuelTank fuelTank;
	Engine* engine;
	Tire* tires[4];
	//Tire** tires;
	//uint8_t tiresCount = 4;
	Battery* battery;
	unsigned odometer = 0;
	unsigned weight = 0;


	void setTires(Tire** tires);

public:
	Car(FuelTank& fuelTank, Engine* engine, Tire* tires[4], Battery* battery, unsigned odometer, unsigned weight);

	unsigned getWeight() const;

	const FuelTank& getFuelTank() const;

	const Engine* getEngine() const;

	void drive(double km);
};

Car* dragRace(Car* car1, Car* car2);