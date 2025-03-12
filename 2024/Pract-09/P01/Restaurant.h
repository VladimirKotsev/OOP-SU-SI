#pragma once
#include <iostream>
#include "Product.h"

//id(уникално цяло число)
//име(с максимална дължина 25 символа);
//брой продукти
//списък от продукти(с произволна дължина, която се подава в конструктора);
//Поддържаме добавяне на продукт
//Поддържаме и метод за получаване на поръчка

class Restaurant
{
private:
	unsigned static count;

	unsigned id;
	char name[25 + 1];
	unsigned productCount = 0;
	Product* products;


public:

	void addProduct();
	void recieveOrder();
};

