#pragma once
#include "CarPart.h"

class Battery : private CarPart
{
private:
	unsigned ampHours = 0;
	char* id = nullptr;

	void setId(char* id);

	void free();
	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other);
public:
	Battery(const char* producer, const char* description, unsigned ampHours, char* id);

	Battery(const Battery& other);
	Battery(Battery&& other) noexcept;

	Battery& operator=(const Battery& other);
	Battery& operator=(Battery&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
};

