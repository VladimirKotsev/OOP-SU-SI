#include "OptionalDouble.h"

void OptionalDouble::copyFrom(const OptionalDouble& other)
{
	set(*other.number);
}
void OptionalDouble::free()
{
	delete this->number;
}
bool OptionalDouble::isPresent()
{
	return this->number;
}
void OptionalDouble::set(double number)
{
	this->number = new double;
	*this->number = number;
};
double OptionalDouble::get() const
{
	if (!this->number)
	{
		throw std::exception("Nullpointer!");
	}

	return *this->number;
}

OptionalDouble::OptionalDouble(double number)
{
	this->set(number);
}

OptionalDouble& OptionalDouble::operator=(const OptionalDouble& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
OptionalDouble::OptionalDouble(const OptionalDouble& other)
{
	copyFrom(other);
}
OptionalDouble::~OptionalDouble()
{
	free();
}

void OptionalDouble::empty()
{
	if (!number)
	{
		throw std::exception("Already empty!");
	}

	this->number = nullptr;
}

std::ostream& operator<<(std::ostream& os, const OptionalDouble& opt)
{
	return os << opt.get();
}