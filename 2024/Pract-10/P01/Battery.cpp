#include "Battery.h"
#pragma warning (disable: 4996)

void Battery::setId(char* id)
{
	if (id == nullptr)
		throw std::invalid_argument("Invalid battery id!");

	this->id = new char[strlen(id)];
	strcpy(this->id, id);
}

void Battery::free()
{
	delete[] id;
}

void Battery::copyFrom(const Battery& other)
{
	size_t size = strlen(other.id);
	this->id = new char[size + 1];
	strcpy(this->id, other.id);

	this->ampHours = other.ampHours;
}

void Battery::moveFrom(Battery&& other)
{
	this->id = other.id;
	other.id = nullptr;
	this->ampHours = other.ampHours;
	other.ampHours = 0;
}

Battery::Battery(const char* producer, const char* description, unsigned ampHours, char* id)
	: CarPart(producer, description)
{
	this->ampHours = ampHours;
	setId(id);
}
Battery::Battery(const Battery& other) : CarPart(other)
{
	copyFrom(other);
}

Battery::Battery(Battery&& other) noexcept : CarPart(std::move(other))
{
	moveFrom(std::move(other));
}

Battery& Battery::operator=(const Battery& other)
{
	if (this != &other)
	{
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Battery& Battery::operator=(Battery&& other) noexcept
{
	if (this != &other)
	{
		CarPart::operator=(std::move(other));
		free();
		copyFrom(other);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Battery& battery)
{
	os << (CarPart&)battery;
	return os << "- " << battery.ampHours << " Ah";
}
