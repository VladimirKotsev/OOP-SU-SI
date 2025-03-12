#pragma once
#include "OptionalDouble.h"

class OptionalDoubleVector
{
private:
	OptionalDouble* optionals = nullptr;
	size_t count = 0;
	size_t capacity = 4;

	void resize(size_t newCapacity);
	void free();
	void copyFrom(const OptionalDoubleVector& other);
	void sizeArray();

public:
	OptionalDoubleVector();
	~OptionalDoubleVector();
	OptionalDoubleVector& operator=(const OptionalDoubleVector& other);

	void push_back(const OptionalDouble& optional);
	void pop_back();
	void insert(const OptionalDouble& optional, size_t index);

	void erase(size_t index);
	void clear();
	bool empty() const;

	size_t getSize() const;
	size_t getCapacity() const;

	OptionalDouble operator[](size_t index);

	friend std::ostream& operator<<(std::ostream& os, const OptionalDoubleVector& vector);
};
