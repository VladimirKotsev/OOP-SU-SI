#include <iostream>

struct Triplet
{
	int first;
	int second;
	int third;
};

// намира и връща индекса на най-малката наредена тройка в масива triplets
// сравнява две наредени тройки по компоненти и връща
// число < 0, ако lhs < rhs
// число == 0, aко lhs == rhs
// число > 0, aко lhs > rhs
int compare(const Triplet& lhs, const Triplet& rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second == rhs.second)
			return lhs.third - rhs.third;

		return lhs.second - rhs.second;
	}

	return lhs.first - rhs.first;
}


int findMinTripletIndex(const Triplet* triplets, int size)
{
	if (!triplets)
		return -1;

	int index = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (compare(triplets[index], triplets[i]) > 0)
			index = i;
	}

	return index;
}

void printTriplet(const Triplet& triplet)
{
	std::cout << "(";
	std::cout << triplet.first << ", ";
	std::cout << triplet.second << ", ";
	std::cout << triplet.third << ")" << std::endl;
}

void printMinimumTriplet(const Triplet* triplets, int size)
{
	if (!triplets)
		return;

	int index = findMinTripletIndex(triplets, size);
	printTriplet(triplets[index]);
}


// чете наредена тройка от стандартния вход
void readTriplet(Triplet& triplet)
{
	std::cin >> triplet.first;
	std::cin >> triplet.second;
	std::cin >> triplet.third;
}

int main()
{
	int n = 0;
	std::cin >> n;

	Triplet* arr = new Triplet[n];

	for (size_t i = 0; i < n; i++)
	{
		Triplet triplet;
		readTriplet(triplet);

		arr[i] = triplet;
	}

	//std::cout << findMinTripletIndex(arr, n);

	printMinimumTriplet(arr, n);

	delete[] arr;
}

