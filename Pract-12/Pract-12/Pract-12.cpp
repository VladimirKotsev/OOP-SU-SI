#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    vector.pop_back();
    std::cout << vector[2];
    vector.pop_back();
    vector.pop_back();
    vector.push_back(5);
    std::cout << vector[1];
}

