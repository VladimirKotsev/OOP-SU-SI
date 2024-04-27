#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
private:
	unsigned horsePower = 0;

public:
	Engine(const char* producer, const char* description, unsigned horsePower);

	unsigned getHorsePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};

