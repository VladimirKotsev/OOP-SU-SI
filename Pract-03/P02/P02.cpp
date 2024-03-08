#include <iostream>
#include <fstream>

namespace Constants
{
	const int COLOR_NAME = 8;
	const int FILE_MAX_NAME = 1024;
	const int COLOR_CODE_MAX = 10;
	const int COLOR_MAX = COLOR_NAME + COLOR_CODE_MAX;
}

struct Color
{
	char name[Constants::COLOR_NAME];
	int code;
};

size_t getFileSize(std::ifstream& ifs)
{
	if (!ifs.is_open())
		return 0;

	ifs.seekg(0, std::ios::end);
	size_t fileSize = ifs.tellg();
	return fileSize;
}

size_t colorshoInFile(const char* filePath)
{
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
		return 0;

	size_t fileSize = getFileSize(inFile);
	inFile.close();
	return fileSize / sizeof(Color);
}

Color findColorByName(const char* name, const char* filePath)
{
	std::ifstream inFile(filePath);
	if (!inFile.is_open())
		return {"ERROR", -1 };

	int size = colorshoInFile(filePath);
	Color* colors = new Color[size];
	inFile.read((char*)colors, size);

	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, colors[i].name) == 0)
		{
			inFile.close();
			return colors[i];
		}
	}

	inFile.close();
	return { "ERROR", -1 };
}

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
	outFile.flush();
	outFile.close();
}

void printColor(const Color& color)
{
	std::cout << "Color: " << color.name << " -> " << color.code << std::endl;
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

	char colorName[Constants::FILE_MAX_NAME];
	std::cin >> colorName;

	printColor(findColorByName(colorName, "text.txt"));

	delete[] colors;
}
