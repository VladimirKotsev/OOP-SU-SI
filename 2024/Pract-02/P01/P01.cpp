#include <iostream>
#include <fstream>

constexpr unsigned BUFFER_SIZE = 255;

void readFromFile(std::ifstream& inFile, char* input)
{
    if (!inFile.is_open())
        return;

    inFile.getline(input, BUFFER_SIZE);
}

unsigned countOfCharacters(char* str, bool (*pred)(char c))
{
    unsigned count = 0;
    while (*str)
    {
        if (pred(*str))
            count++;

        str++;
    }

    return count;
}

int main()
{
    char input[BUFFER_SIZE];
    std::ifstream inFile;
    inFile.open("test.txt");

    readFromFile(inFile, input);
    inFile.close();

    unsigned count = countOfCharacters(input, [](char c) -> bool {return (c != ' '); });
    std::cout << count;
}
