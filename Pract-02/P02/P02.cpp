#include <iostream>
#include <fstream>

constexpr unsigned BUFFER_SIZE = 255;

struct Triplet
{
    int x;
    int y;
    int z;
};

struct Tuple
{
    int sum;
    int product;
};

int sumNumbers(const Triplet& triplet)
{
    return triplet.x + triplet.y + triplet.z;
}

int multiplyNumbers(const Triplet& triplet)
{
    return triplet.x * triplet.y * triplet.z;
}

void readFromFile(std::ifstream& inFile, char* sum, char* product)
{
    if (!inFile.is_open())
        return;

     inFile.getline(sum, BUFFER_SIZE, '\n');
     inFile.getline(product, BUFFER_SIZE, '\n');
}

void readFromFile(std::ifstream& inFile, int& sum, int& product)
{
    if (!inFile.is_open())
        return;

    inFile >> sum;
    inFile >> product;
}

void writeOnFile(std::ofstream& outFile, const Triplet& triplet)
{
    if (!outFile.is_open())
        return;

    outFile << sumNumbers(triplet) << std::endl;
    outFile << multiplyNumbers(triplet);
}


Triplet readTriplet()
{
    Triplet triplet;
    std::cin >> triplet.x;
    std::cin >> triplet.y;
    std::cin >> triplet.z;

    return triplet;
}

int getSubstraction(int sum, int product)
{
    if (sum > product)
        return (sum - product);
    else if (sum < product)
        return (product - sum);

    return 0;
}

int main()
{
    Triplet triplet = readTriplet();

    std::ofstream outFile;
    outFile.open("result.txt");

    writeOnFile(outFile, triplet);

    outFile.close();

    int sum = 0;
    int product = 0;
    std::ifstream inFile;
    inFile.open("result.txt");

    readFromFile(inFile, sum, product);

    std::cout << sum << " " << product;

    std::cout << std::endl;
    std::cout << "Substraction of sum and product: " << getSubstraction(sum, product);

    inFile.close();
}
