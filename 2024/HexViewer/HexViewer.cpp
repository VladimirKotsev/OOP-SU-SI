#include <iostream>
#include <fstream>

struct HexViewer
{
    u
};

size_t getFileSize(std::istream& stream)
{
    size_t current = stream.tellg();
    stream.seekg(std::ios::end, 0);
    size_t size = stream.tellg();
    stream.seekg(current, 0);
    return size;

}

int main()
{
    std::cout << "Hello World!\n";
}

