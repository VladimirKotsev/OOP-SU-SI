#include <iostream>
#include <fstream>
#include "P03.h"

namespace Constants
{
    const int COMPANY_NAME_MAX = 25;
}

struct Advertisement
{
    char companyName[Constants::COMPANY_NAME_MAX];
    int numberOfEngineers;
    int weekendsInYear;
    int salary;
};

size_t getFileSize(std::ifstream& inFile)
{
    if (!inFile.is_open())
        return 0;

    inFile.seekg(0, std::ios::end);
    return inFile.tellg();
}

void printAdvertisement(const Advertisement ad)
{
    std::cout << "Company name: " << ad.companyName << std::endl;
    std::cout << "Number of engineers: " << ad.numberOfEngineers << std::endl;
    std::cout << "Non-working days in a year: " << ad.weekendsInYear << std::endl;
    std::cout << "Salary: " << ad.salary << std::endl;
}

void printAllFilteredAdvertisements(const Advertisement* ads, int size, size_t minSalary)
{
    for (size_t i = 0; i < size; i++)
    {
        if (ads[i].salary > minSalary)
            printAdvertisement(ads[i]);
    }
}

Advertisement readAdvertisement()
{
    Advertisement ad;
    std::cout << "Company name: ";
    std::cin >> ad.companyName;
    std::cout << "Number of engineers: ";
    std::cin >> ad.numberOfEngineers;
    std::cout << "Non-working days in a year: ";
    std::cin >> ad.weekendsInYear;
    std::cout << "Salary: ";
    std::cin >> ad.salary;

    return ad;
}

void readAdvertisements(Advertisement* ads, int size)
{
    for (size_t i = 0; i < size; i++)
        ads[i] = readAdvertisement();
}

void filterOffer(const char* filePath, size_t minSalary) // cout all advertisments above minSalary
{
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile.is_open())
        return;

    size_t size = getFileSize(inFile) / sizeof(Advertisement);
    Advertisement* ads = new Advertisement[size * sizeof(Advertisement)];
    inFile.read((char*)ads, getFileSize(inFile));

    printAllFilteredAdvertisements(ads, size, minSalary);
    inFile.close();
    delete[] ads;
}

bool findOffer(const char* filePath, const char* name)
{
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile.is_open())
        return false;

    size_t size = getFileSize(inFile) / sizeof(Advertisement);
    Advertisement* ads = new Advertisement[size];
    inFile.read((char*)ads, getFileSize(inFile));

    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(ads[i].companyName, name))
            return true;
    }

    return false;
}

void writeToFile(const char* fileName, const Advertisement* ads, int size)
{
    if (!ads)
        return;

    std::ofstream outFile(fileName, std::ios::binary | std::ios::app);
    if (!outFile.is_open())
        return;

    outFile.write((const char*)ads, size * sizeof(Advertisement));
    outFile.close();
}



int main()
{
    int n = 0;
    std::cin >> n;
    Advertisement* ads = new Advertisement[n];
    readAdvertisements(ads, n);

    writeToFile("text.txt", ads, n);

    size_t minSalary = 0;
    std::cin >> minSalary;
    filterOffer("text.txt", minSalary);
}
