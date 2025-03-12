#include <iostream>
#include <fstream>

int getCountOfSymbol(std::ifstream& ifs, char symbol)
{
    if (!ifs.is_open())
        return -1;

    int count = 0;
    char current;

    while (ifs.get(current))
    {
        if (current == symbol)
            count++;
    }

    return count;
}

int main()
{
    std::cout << "Hello World!\n";
}
