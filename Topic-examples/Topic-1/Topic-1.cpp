#include <iostream>
#include <cmath>

struct Point
{
    int x;
    int y;
};

struct Triangle
{
    Point A;
    Point B;
    Point C;
};

double getDistance(const Point& A, const Point& B)
{
    return abs(sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2)));
}

double getArea(const Triangle& triangle)
{
    double a = getDistance(triangle.A, triangle.B);
    double b = getDistance(triangle.B, triangle.C);
    double c = getDistance(triangle.C, triangle.A);
    double p = (a + b + c) / 2;

    return sqrt(p*(p - a)*(p - b)*(p - c));
}

void swapTriangles(Triangle& a, Triangle& b)
{
	Triangle temp = a;
	a = b;
	b = temp;
}

void sortTrianglesByArea(Triangle arr[], unsigned size)
{
	unsigned lastSwapedIndex = size - 1;
	for (int i = 0; i < size - 1; i++)
	{
		int currentIterLastSwapped = 0;
		for (int j = 0; j < lastSwapedIndex; j++)
		{
			if (getArea(arr[j]) > getArea(arr[j + 1]))
			{
				swapTriangles(arr[j], arr[j + 1]);
				currentIterLastSwapped = j;
			}
		}
		if (currentIterLastSwapped == 0)
			return;
		lastSwapedIndex = currentIterLastSwapped;
	}
}

void printArray(Triangle arr[], int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << "Triangle " << i << ": " << getArea(arr[i]) << std::endl;
}

int main()
{
    Triangle triangle1 = {{1, 2}, {3, 4}, {2, 5}};
    Triangle triangle2 = {{3, 2}, {3, 4}, {2, 5}};
    Triangle triangle3 = {{5, 2}, {3, 3}, {6, 2}};

	Triangle* arr = new Triangle[3];
	arr[0] = triangle1;
	arr[1] = triangle2;
	arr[2] = triangle3;

	sortTrianglesByArea(arr, 3);
	printArray(arr, 3);

	delete[] arr;
}

