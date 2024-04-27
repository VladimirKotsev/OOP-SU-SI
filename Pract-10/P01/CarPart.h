#pragma once
#include <iostream>

class CarPart
{
private:
	static unsigned counter;
	unsigned id;
	char* producer = nullptr;
	char* description = nullptr;

	void setProducer(const char* producer);
	void setDescription(const char* producer);

	void free();
	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other);

public:
	CarPart(const char* producer, const char* description);

	CarPart(const CarPart& other);
	CarPart(CarPart&& other) noexcept;

	CarPart& operator=(const CarPart& other);
	CarPart& operator=(CarPart&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& carPart);

	~CarPart();
};

