#pragma once
#include <iostream>

class Product
{
private:
	static unsigned count;

	unsigned id;
	char name[25 + 1];

public:
	Product(char* name);
};

