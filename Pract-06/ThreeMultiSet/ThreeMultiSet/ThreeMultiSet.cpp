#include <iostream>

#include "ThreeMultiSet.h"

void ThreeMultiSet::free()
{
	delete[] this->buckets;
	this->bucketCount = 0;
	this->buckets = nullptr;
}
void ThreeMultiSet::copyFrom(const ThreeMultiSet& other)
{
	this->buckets = new uint8_t[other.bucketCount];

	for (int i = 0; i < other.bucketCount; i++)
		this->buckets[i] = other.buckets[i];

	this->bucketCount = other.bucketCount;
	this->maxElement = other.maxElement;
}

//Big 4

ThreeMultiSet::ThreeMultiSet(unsigned maxElement)
{
	if (maxElement > 0)
		this->maxElement = maxElement - 1;

	this->elementsInBucket = (maxElement / this->bucketCount) + 1;
	this->buckets = new uint8_t[this->elementsInBucket]{ 0 };
}
ThreeMultiSet::ThreeMultiSet(const ThreeMultiSet& other)
{
	this->copyFrom(other);
}
ThreeMultiSet& ThreeMultiSet::operator=(const ThreeMultiSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
ThreeMultiSet::~ThreeMultiSet()
{
	free();
}

void ThreeMultiSet::clear()
{
	for (size_t i = 0; i < this->elementsInBucket; i++)
		this->buckets[i] = 0;
}

int ThreeMultiSet::count(int number) const
{
	if (number > this->maxElement)
		return 0;

	unsigned bucket = number / this->bucketCount;
	unsigned index = number % this->bucketCount;

	uint8_t mask = 1;
	mask <<= (this->bucketCount - index - 1) * 2;
	bool isFirstUp = (this->buckets[bucket] & mask) == mask;
	mask <<= 1;
	bool isSecondUp = (this->buckets[bucket] & mask) == mask;

	return isFirstUp * (1 << 0) + isSecondUp * (1 << 1);
}

int ThreeMultiSet::count() const
{
	int allCount = 0;
	for (size_t i = 0; i < this->maxElement; i++)
	{
		allCount += this->count(i);
	}

	return allCount;
}

unsigned ThreeMultiSet::unique() const
{
	unsigned toReturn = 0;
	for (size_t i = 0; i < this->maxElement; i++)
	{
		if (this->count(i) == 1)
			toReturn++;
	}

	return toReturn;
}

void ThreeMultiSet::print() const
{
	for (size_t i = 0; i < this->maxElement; i++)
	{
		unsigned count = this->count(i);
		if (count >= 1)
			std::cout << "Number: " << i << " occured: " << count << std::endl;
	}
}

int ThreeMultiSet::getMax() const
{
	for (int i = this->maxElement; i >= 0; i--)
	{
		if (this->count(i) >= 1)
			return i;
	}

	return -1;
}

int ThreeMultiSet::getMin() const
{
	for (size_t i = 0; i < this->maxElement; i++)
	{
		if (this->count(i) >= 1)
			return i;
	}

	return -1;
}

bool ThreeMultiSet::insert(unsigned number)
{
	if (number >= this->maxElement || number < 0)
		return false;

	unsigned bucket = number / this->bucketCount;
	unsigned index = number % this->bucketCount;

	uint8_t& currBucket = this->buckets[bucket];
	unsigned count = this->count(number);

	if (count == 3)
		return false;

	uint8_t mask = 1;
	mask <<= (this->bucketCount - index - 1) * 2;
	count++;
	if (count % 2 != 0)
		currBucket |= mask;
	else
	{
		mask = ~mask;
		currBucket &= mask;
		mask = ~mask;
	}
	mask <<= 1;
	if (count > 1)
		currBucket |= mask;

	return true;
}

bool ThreeMultiSet::remove(unsigned number)
{
	unsigned bucket = number / this->bucketCount;
	unsigned index = number % this->bucketCount;

	uint8_t& currBucket = this->buckets[bucket];
	unsigned count = this->count(number);
	if (count == 0)
		return false;

	count--;
	uint8_t mask = 1;
	mask <<= (this->bucketCount - index - 1) * 2;
	if (count % 2 != 0)
		currBucket |= mask;
	else
	{
		mask = ~mask;
		currBucket &= mask;
		mask = ~mask;
	}
	mask <<= 1;
	if (count > 1)
		currBucket |= mask;
}

