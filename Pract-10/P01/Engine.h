#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
private:
	unsigned horsePower = 0;

public:
	Engine(char* producer, char* description, unsigned horsePower);

	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};

