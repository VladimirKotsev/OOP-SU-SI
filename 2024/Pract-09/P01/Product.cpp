#include "Product.h"

unsigned Product::count = 0;
Product::Product(char* name)
{
	this->id = count++;
	strcpy(this->name, name);
}
