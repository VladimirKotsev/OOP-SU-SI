#include <iostream>
#include <fstream>
#include <sstream>

namespace Constants
{
    const int MAX_ROW = 100; 
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void writeMatrixToFile(const char* fileName, int** matrix, size_t rowCount, size_t colCount)
{
    if (!fileName || !matrix)
        return;

    std::ofstream outFile(fileName);
    if (!outFile.is_open())
        return;

    for (size_t i = 0; i < rowCount; i++)
    {
        for (size_t j = 0; j < colCount; j++)
        {
            outFile << matrix[i][j];
            if (j != (colCount - 1))
                outFile << ',';
        }

        if (i != (rowCount - 1))
            outFile << '|';
    }

    outFile.close();
}

int sumForIndex(int** matrix1, int** matrix2, int i, int j, size_t max)
{
    int result = 0;
    for (size_t k = 0; k < max; k++)
    {
        result += matrix1[i][k] * matrix2[k][j];
    }

    return result;
}

int** multiplyMatrixes(int** matrix1, int** matrix2, size_t rowCount1, size_t colCount1, size_t rowCount2, size_t colCount2)
{
    if (!matrix1 || !matrix2)
        return nullptr;

    if (rowCount1 != colCount2)
        return nullptr;

    int** toReturn = new int* [rowCount1];
    for (size_t i = 0; i < rowCount1; i++)
        toReturn[i] = new int[colCount2];

    for (size_t i = 0; i < rowCount1; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < colCount2; j++)
        {
            toReturn[i][j] = sumForIndex(matrix1, matrix2, i, j, colCount1);
        }
    }

    return toReturn;
}

void readMatrixFromFile(const char* fileName, int** matrix, size_t& rowCount, size_t& colCount)
{
    if (!fileName)
        return;

    std::ifstream inFile(fileName);
    if (!inFile.is_open())
        return;

    size_t rowIndex = 0;
    size_t colIndex = 0;

    char row[Constants::MAX_ROW];
    inFile.getline(row, Constants::MAX_ROW);
    std::stringstream ss(row);

    while (!ss.eof())
    {
        char c = ss.peek();

        if (c == ',')
        {
            colIndex++;
        }
        else if (c == '|')
        {
            rowIndex++;
            colCount = colIndex + 1;
            colIndex = 0;
        }
        else if (isDigit(c))
        {
            int num = c - '0';
            matrix[rowIndex][colIndex] = num;
        }
    }

    rowCount = rowIndex + 1;
    inFile.close();
}

int main()
{
    
}
