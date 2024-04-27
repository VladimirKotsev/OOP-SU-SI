#include "CarPart.h"
#pragma warning (disable: 4996)

unsigned CarPart::counter = 1;

void CarPart::setProducer(const char* producer)
{
	if (producer == nullptr)
		throw std::invalid_argument("Invalid car part producer!");

	size_t size = strlen(producer);
	this->producer = new char[size + 1];
	strcpy(this->producer, producer);
}
void CarPart::setDescription(const char* description)
{
	if (description == nullptr)
		throw std::invalid_argument("Invalid car part description!");

	size_t size = strlen(description);
	this->description = new char[size + 1];
	strcpy(this->description, description);
}

void CarPart::free()
{
	delete[] producer;
	delete[] description;
}

void CarPart::copyFrom(const CarPart& other)
{
	size_t length = strlen(other.producer);
	this->producer = new char[length + 1];
	strcpy(this->producer, other.producer);

	length = strlen(other.description);
	this->description = new char[length + 1];
	strcpy(this->description, other.description);

	this->counter = other.counter;
}

void CarPart::moveFrom(CarPart&& other)
{
	this->producer = other.producer;
	other.producer = nullptr;
	this->description = other.description;
	other.description = nullptr;
	id = other.id;
	other.id = 0;
}

CarPart::CarPart(const char* producer, const char* description)
{
	id = counter;
	setProducer(producer);
	setDescription(description);
	counter++;
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart::CarPart(CarPart&& other) noexcept
{
	moveFrom(std::move(other));

}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
CarPart& CarPart::operator=(CarPart&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CarPart::~CarPart()
{
	free();
}

std::ostream& operator<<(std::ostream& os, const CarPart& carPart)
{
	return os << '(' << carPart.id << ')' << " by " << carPart.producer << " - " << carPart.description << ' ';
}

