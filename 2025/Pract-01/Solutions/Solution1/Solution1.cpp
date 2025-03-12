#include <iostream>
#include <cmath>

struct Point
{
    int x, y;
};

Point readFromConsole()
{
    int x, y;
    std::cin >> x >> y;
    return { x, y };
}

void printPoint(const Point& p)
{
    std::cout << '(' << p.x << ", " << p.y << ')';
}

double distanceFromCenter(const Point& p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

double distanceBetweenTwo(const Point& p1, const Point& p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

struct Triangle
{
    Point A;
    Point B;
    Point C;
    char type[10];
};

Triangle readTriangle()
{
    Triangle tr;
    tr.A = readFromConsole();
    tr.B = readFromConsole();
    tr.C = readFromConsole();
}

void PrintTriangle(const Triangle& triangle)
{
    std::cout << "A: ";
    printPoint(triangle.A);
    std::cout << '/n';

    std::cout << "B: ";
    printPoint(triangle.B);
    std::cout << '/n';

    std::cout << "C: ";
    printPoint(triangle.C);
    std::cout << '/n';
}

double getArea(const Triangle& triangle)
{
    double a = distanceBetweenTwo(triangle.A, triangle.B);
    double b = distanceBetweenTwo(triangle.B, triangle.C);
    double c = distanceBetweenTwo(triangle.A, triangle.C);
    double semi = (a + b + c) / 2;
    return sqrt(semi * (semi - a) * (semi - b) * (semi - c));
}

double getPerimeter(const Triangle& triangle)
{
    double a = distanceBetweenTwo(triangle.A, triangle.B);
    double b = distanceBetweenTwo(triangle.B, triangle.C);
    double c = distanceBetweenTwo(triangle.A, triangle.C);
    return a + b + c;
}

const char* getType(const Triangle& triangle)
{
    double a = distanceBetweenTwo(triangle.A, triangle.B);
    double b = distanceBetweenTwo(triangle.B, triangle.C);
    double c = distanceBetweenTwo(triangle.A, triangle.C);

    if (a == b && b == c)
        return "equilateral";
    else if (a == b || a == c || b == c)
        return "isosceles";
    else
        return "scalene";
}

int main()
{
  
}

