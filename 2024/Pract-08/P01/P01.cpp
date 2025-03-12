#include <iostream>
#include "OptionalDoubleVector.h"

int main()
{
	OptionalDouble opt1;
	OptionalDouble opt2;
	OptionalDouble opt3;

	opt1.set(3.14);
	opt2.set(5.16);
	opt3.set(7.91);
	OptionalDoubleVector vector;
	vector.push_back(opt1);
	vector.push_back(opt2);
	vector.push_back(opt3);
	vector.push_back(opt3);
	vector.push_back(opt3);
	std::cout << vector;

	vector.insert(opt1 ,2);
	vector.erase(0);
	vector.erase(0);
	std::cout << vector;
}
