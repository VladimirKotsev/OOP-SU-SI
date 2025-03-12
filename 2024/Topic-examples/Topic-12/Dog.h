#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	void talk() const override;
	Animal* clone() const override;
};