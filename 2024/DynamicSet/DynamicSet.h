#pragma once
#include <iostream>

class DynamicSet
{
private:
	uint8_t* buckets = nullptr;
	size_t bucketCount = 0;
	size_t elementsInBucket = sizeof(uint8_t) * 8;
	unsigned N = 0;
		
	void free();
	void copyFrom(const DynamicSet& other);
	void moveFrom(DynamicSet&& other);

	unsigned getMaskShiftLeft(unsigned num) const;
	unsigned getBucketIndex(unsigned num) const;
	unsigned getInBucketIndex(unsigned num) const;
public:

	DynamicSet(unsigned n);

	DynamicSet(const DynamicSet& other);
	DynamicSet& operator=(const DynamicSet& other);

	DynamicSet(DynamicSet&& other) noexcept;
	DynamicSet& operator=(DynamicSet&& other) noexcept;

	~DynamicSet();

	void addNumber(unsigned num);
	void removeNumber(unsigned num);

	bool contains(unsigned num) const;
	void print() const;

	friend DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
	friend DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs);
};

