#pragma once
#include "CarPart.h"

class Tire : public CarPart
{
private:
	unsigned width = 155;
	unsigned sidewallWidth = 30;
	unsigned size = 13;

	void setWidth(unsigned width);
	void setSidewallWidth(unsigned width);
	void setSize(unsigned size);
public:
	Tire(const char* producer, const char* description, unsigned width, unsigned sidewallWidth, unsigned size);

	friend std::ostream& operator<<(std::ostream& os, const Tire& tire);
};

