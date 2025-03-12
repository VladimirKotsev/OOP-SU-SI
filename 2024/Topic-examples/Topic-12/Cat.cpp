#include "Cat.h"

Cat::Cat() : Animal(AnimalType::Cat)
{
}

void Cat::talk() const
{
	std::cout << "Meow meow" << std::endl;
}

Animal* Cat::clone() const
{
	Animal* animal = new (std::nothrow) Cat(*this);
	return animal;
}


