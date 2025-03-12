#include <iostream>
#include <fstream>

namespace Constants
{
	const int COLOR_NAME = 8;
	const int FILE_MAX_NAME = 1024;
}

struct Color
{
	char name[Constants::COLOR_NAME];
	int code;
};

Color readColor()
{
	Color color;

	std::cin >> color.name;
	std::cin >> color.code;

	return color;
}

void readColors(Color* colors, int size)
{
	for (size_t i = 0; i < size; i++)
		colors[i] = readColor();
}

void writeToFile(const char* fileName, const Color* colors, int size)
{
	std::ofstream outFile(fileName, std::ios::app | std::ios::binary);
	if (!colors)
		return;

	if (!outFile.is_open())
		return;

	outFile.write((const char*)colors, sizeof(Color) * size);
	outFile.close();
}

int main()
{
	int n = 0;
	char fileName[Constants::FILE_MAX_NAME];
	std::cin >> n;

	Color* colors = new Color[n];
	readColors(colors, n);

	std::cin >> fileName;
	writeToFile(fileName, colors, n);

	delete[] colors;

	int* arr = new int[0];
}

