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
	Tire(char* producer, char* description, unsigned width, unsigned sidewallWidth, unsigned size) 
		: CarPart(producer, description)
	{
		setWidth(width);
		setSidewallWidth(sidewallWidth);
		setSize(size);
	}

	friend std::ostream& operator<<(std::ostream& os, const Tire& tire);
};

