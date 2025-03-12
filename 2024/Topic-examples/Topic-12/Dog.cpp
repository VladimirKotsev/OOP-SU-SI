#include "Dog.h"

Dog::Dog() : Animal(AnimalType::Dog)
{
}

void Dog::talk() const
{
	std::cout << "Bark bark" << std::endl;
}

Animal* Dog::clone() const
{
	Animal* animal = new (std::nothrow) Dog(*this);
	return animal;

}
