#include <iostream>
#include <fstream>

const char FILENAME[] = "result.txt";

int readDifference()
{
	std::ifstream ifs(FILENAME);

	if (!ifs.is_open())
		return -1;

	int sum, product;
	ifs >> sum >> product;
	return product - sum;
}

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::ofstream ofs(FILENAME);

	if (!ofs.is_open())
		return -1;

	int sum = a + b + c;
	int product = a * b * c;
	ofs << sum << ' ' << product;

	ofs.close();
}