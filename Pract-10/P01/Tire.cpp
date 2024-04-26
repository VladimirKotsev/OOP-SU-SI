#include "Tire.h"

void Tire::setWidth(unsigned width)
{
	if (width < 155 || width > 365)
		throw std::invalid_argument("Invalid tire width!");

	this->width = width;
}

void Tire::setSidewallWidth(unsigned width)
{
	if (width < 30 || width > 80)
		throw std::invalid_argument("Invalid tire sidewall width!");

	this->sidewallWidth = width;
}

void Tire::setSize(unsigned size)
{
	if (size < 13 || size > 21)
		throw std::invalid_argument("Invalid tire size!");

	this->size = size;
}

std::ostream& operator<<(std::ostream& os, const Tire& tire)
{
	os << (CarPart&)tire;
	return os << tire.width << '/' << tire.sidewallWidth << 'R' << tire.size;
}
