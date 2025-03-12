#include "DynamicSet.h"

void DynamicSet::free()
{
	delete[] buckets;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
	buckets = new uint8_t[other.bucketCount];
	bucketCount = other.bucketCount;
	N = other.N;
	for (size_t i = 0; i < other.bucketCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void DynamicSet::moveFrom(DynamicSet&& other)
{
	buckets = other.buckets;
	other.buckets = nullptr;

	N = other.N;
	bucketCount = other.bucketCount;

	other.N = other.bucketCount = 0;
}

unsigned DynamicSet::getMaskShiftLeft(unsigned num) const
{
	return elementsInBucket - getInBucketIndex(num);
}

unsigned DynamicSet::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

unsigned DynamicSet::getInBucketIndex(unsigned num) const
{
	return num % elementsInBucket;
}

DynamicSet::DynamicSet(unsigned n)
{
	N = n;
	bucketCount = N / elementsInBucket + 1;
	buckets = new uint8_t[bucketCount]{ 0 };
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicSet::DynamicSet(DynamicSet&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicSet& DynamicSet::operator=(DynamicSet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

void DynamicSet::addNumber(unsigned num)
{
	if (num > N)
		return;

	int mask = (1 << getMaskShiftLeft(num));
	unsigned index = getBucketIndex(num);

	buckets[index] |= mask;
}

void DynamicSet::removeNumber(unsigned num)
{
	if (num >= N)
		return;

	int mask = (1 << getMaskShiftLeft(num));
	unsigned index = getBucketIndex(num);

	mask = ~mask;
	buckets[index] &= mask;
}

bool DynamicSet::contains(unsigned num) const
{
	if (num >= N)
		return false;

	unsigned index = getBucketIndex(num);
	unsigned mask = (1 << getMaskShiftLeft(num);
	bool result = (buckets[index] & (1 << getMaskShiftLeft(num) == buckets[index]);

	return result;
}

void DynamicSet::print() const
{

}

DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	unsigned N = std::max(lhs.N, rhs.N);
	DynamicSet toReturn(N);

	for (size_t i = 0; i < N; i++)
	{
		if (lhs.contains(i) || rhs.contains(i))
			toReturn.addNumber(i);
	}

	return toReturn;
}

DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	unsigned N = std::max(lhs.N, rhs.N);
	DynamicSet toReturn(N);

	for (size_t i = 0; i < N; i++)
	{
		if (lhs.contains(i) && rhs.contains(i))
			toReturn.addNumber(i);
	}

	return toReturn;
}
