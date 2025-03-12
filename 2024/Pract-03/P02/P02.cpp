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

size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();

	file.seekg(0, std::ios::end);
	size_t size = file.tellg();

	file.seekg(currentPos);
	return size;
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
	if(!name || !filePath)
		return {"Error", -1};

	std::ifstream inFile(filePath);
	if (!inFile.is_open())
		return {"ERROR", -1 };

	int size = colorshoInFile(filePath);
	Color* colors = new Color[size];
	inFile.read((char*)colors, getFileSize(inFile));

	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(name, colors[i].name) == 0)
		{
			inFile.close();
			Color toReturn = colors[i];
			delete[] colors;
			return toReturn;
		}
	}

	inFile.close();
	delete[] colors;
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
	if (!colors)
		return;

	for (size_t i = 0; i < size; i++)
		colors[i] = readColor();
}

void writeToFile(const char* fileName, const Color* colors, int size)
{
	if (!colors || !fileName)
		return;

	std::ofstream outFile(fileName, std::ios::app | std::ios::binary);

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

	writeToFile("text.txt", colors, n);

	char colorName[Constants::FILE_MAX_NAME];
	std::cin >> colorName;

	printColor(findColorByName(colorName, "text.txt"));

	delete[] colors;
}
