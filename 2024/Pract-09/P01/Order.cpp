#include "Order.h"

unsigned Order::count = 0;
void Order::setName(char* name)
{
	if (!name)
		throw std::invalid_argument("Invalid order name");

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Order::Order(char* name, Product* products, unsigned productCount)
{
	count++;
	this->id = count;

}
