#include <iostream>
#include <fstream>
#include <algorithm>

const char INPUT_FILENAME[] = "input.txt";
const char ASC_FILENAME[] = "ascending.txt";
const char DESC_FILENAME[] = "descending.txt";

int main()
{
    std::ifstream ifs(INPUT_FILENAME);
    if (!ifs.is_open())
        return -1;

    int n = 0;
    if (!(ifs >> n) || n <= 0)
    {
        std::ofstream ofsAsc(ASC_FILENAME);
        std::ofstream ofsDesc(DESC_FILENAME);
        ofsAsc << "0\n";
        ofsDesc << "0\n";
        return 0;
    }

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        ifs >> arr[i];

    ifs.close();

    std::sort(arr, arr + n);
    std::ofstream ofsAsc(ASC_FILENAME);
    if (!ofsAsc.is_open())
        return -1;

    ofsAsc << n << "\n";
    for (int i = 0; i < n; i++)
        ofsAsc << arr[i] << " ";
    ofsAsc.close();

    std::sort(arr, arr + n, std::greater<int>());
    std::ofstream ofsDesc(DESC_FILENAME);
    if (!ofsDesc.is_open())
        return -1;

    ofsDesc << n << "\n";
    for (int i = 0; i < n; i++)
        ofsDesc << arr[i] << " ";
    ofsDesc.close();

    delete[] arr;

    return 0;
}
