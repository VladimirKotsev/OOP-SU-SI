#include <iostream>
#include "Tire.h"
#include "Engine.h"
#include "Battery.h"
#include "Car.h"

int main()
{
    Tire tire1("Nexen", "solid tire", 245, 40, 17);
    Tire tire2("Nexen", "solid tire", 245, 40, 17);
    Tire tire3("Nexen", "solid tire", 245, 40, 17);
    Tire tire4("Nexen", "solid tire", 245, 40, 17);
    Tire* tire[4]{&tire1, &tire2, &tire3, &tire4};

    Engine engine("Audi", "vag group", 130);
    Battery battery("Varta", "best electricity supply", 3, (char*)"2");
    FuelTank fuelTank1(20);
    FuelTank fuelTank2(40);
    Car car1(fuelTank1, &engine, tire, &battery, 15000, 1400);
    Car car2(fuelTank2, &engine, tire, &battery, 15000, 1500);

    Car* winner = dragRace(&car1, &car2);
    std::cout << winner->getWeight();
}

