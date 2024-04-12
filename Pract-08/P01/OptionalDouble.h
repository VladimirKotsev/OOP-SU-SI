#pragma once
#include <iostream>

class OptionalDouble
{
private:
	double* number = nullptr;

	void copyFrom(const OptionalDouble& other);
	void free();
public:
	bool isPresent();
	void set(double number);
	double get() const;

	OptionalDouble() = default;
	OptionalDouble(double number);
	OptionalDouble& operator=(const OptionalDouble& other);
	OptionalDouble(const OptionalDouble& other);
	~OptionalDouble();

	void empty();

	friend std::ostream& operator<<(std::ostream& os, const OptionalDouble& opt);
};