#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
	Cow();
	void talk() const override;
	Animal* clone() const override;
};