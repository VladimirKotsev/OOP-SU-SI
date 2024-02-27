#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    struct Student
    {
        unsigned int id;
        double grade;
    };

    enum Animal
    {
        bison,
        elephant
    };

    Animal animal1 = bison;

    Student myStudent;
    myStudent.id = 5;
    myStudent.grade = 5.60;

    std::cout << myStudent.id << " " << myStudent.grade;
    std::cout << animal1;
}

