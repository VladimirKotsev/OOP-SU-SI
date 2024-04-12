#include "OptionalDoubleVector.h"

OptionalDoubleVector::OptionalDoubleVector() : capacity(8), count(0)
{
	this->optionals = new OptionalDouble[capacity]{0};
}

void OptionalDoubleVector::resize(size_t newCapacity)
{
	OptionalDouble* temp = new OptionalDouble[count]{ 0 };
	for (size_t i = 0; i < count; i++)
		temp[i] = this->optionals[i];

	free();
	this->optionals = new OptionalDouble[newCapacity]{ 0 };

	this->optionals = temp;
	this->capacity = newCapacity;
}

void OptionalDoubleVector::free()
{
	delete[] this->optionals;
}

void OptionalDoubleVector::copyFrom(const OptionalDoubleVector& other)
{
	this->optionals = new OptionalDouble[other.count];

	for (size_t i = 0; i < other.count; i++)
	{
		this->optionals[i] = other.optionals[i];
	}

	this->count = other.count;
	this->capacity = other.capacity;
}

void OptionalDoubleVector::sizeArray()
{
	if (count <= capacity / 4)
		resize(this->capacity / 2);
	else if (count >= capacity)
		resize(this->capacity * 2);
}

OptionalDoubleVector::~OptionalDoubleVector()
{
	free();
}

OptionalDoubleVector& OptionalDoubleVector::operator=(const OptionalDoubleVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void OptionalDoubleVector::push_back(const OptionalDouble& optional)
{
	if (count >= capacity)
		resize(this->capacity * 2);

	optionals[count++] = optional;
}

void OptionalDoubleVector::pop_back()
{
	if (this->count == 0)
		throw std::exception("No elements in sequence");

	if (count - 1 <= capacity / 4)
		resize(this->capacity / 2);
	this->count--;
}

void OptionalDoubleVector::insert(const OptionalDouble& optional, size_t index)
{
	if (index > capacity)
		throw std::exception("At index to add is more than capacity!");

	if (count >= capacity)
		resize(capacity * 2);

	for (int i = count; i > index; i--) //Shift the element to the right
	{
		optionals[i] = optionals[i - 1];
	}

	this->optionals[index] = optional;
	this->count++;
}

void OptionalDoubleVector::erase(size_t index)
{
	if (index > capacity)
		throw std::exception("Invalid index");

	for (int i = index; i < count - 1; i++) //Shift the element to the left
	{
		optionals[i] = optionals[i + 1]; 
	}

	if (count - 1 <= capacity / 4)
		resize(this->capacity / 2);
	this->count--;
}

void OptionalDoubleVector::clear()
{
	free();
	this->capacity = 8;
	this->count = 0;
}

size_t OptionalDoubleVector::getSize() const
{
	return this->count;
}

size_t OptionalDoubleVector::getCapacity() const
{
	return this->capacity;
}

bool OptionalDoubleVector::empty() const
{
	return this->optionals;
}

OptionalDouble OptionalDoubleVector::operator[](size_t index)
{
	return this->optionals[index];
}

std::ostream& operator<<(std::ostream& os, const OptionalDoubleVector& vector)
{
	if (vector.count == 0)
		return os << "No elements in sequence!";

	for (size_t i = 0; i < vector.count; i++)
		os << vector.optionals[i] << ", ";

	os << std::endl;
	return os;
}

