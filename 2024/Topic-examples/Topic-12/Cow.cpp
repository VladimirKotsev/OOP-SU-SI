#include "Cow.h"

Cow::Cow() : Animal(AnimalType::Cow)
{
}

void Cow::talk() const
{
	std::cout << "Muuuu" << std::endl;
}

Animal* Cow::clone() const
{
	Animal* animal = new (std::nothrow) Cow(*this);
	return animal;
}
