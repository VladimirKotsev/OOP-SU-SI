#pragma once
#include <iostream>
#include "Product.h"

class Order
{
	/*id(уникално цяло число)
		име на ресторанта, за който е
		брой продукти
		списък с продуктите.*/
private:
	static unsigned count;

	unsigned id = 0;
	char* name = nullptr;
	unsigned productsCount;
	Product* products = nullptr;

	void free();
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);

	void setName(char* name);
public:
	Order(char* name, Product* products, unsigned productCount);
};

