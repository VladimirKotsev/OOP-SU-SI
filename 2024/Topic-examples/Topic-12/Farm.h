#pragma once
#include "Animal.h"
class Farm
{
public:
	Farm() = default;
	Farm(const Farm& other);


	void addCow();
	void addCat();
	void addDog();

private:
	Animal** animals;
	size_t capacity;
	size_t size;

	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void resize();
	void free();
};

