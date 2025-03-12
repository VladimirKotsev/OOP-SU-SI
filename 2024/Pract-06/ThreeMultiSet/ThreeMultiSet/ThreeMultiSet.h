#pragma once

class ThreeMultiSet
{
private:
	uint8_t* buckets = nullptr;
	unsigned elementsInBucket = 0;
	unsigned bucketCount = sizeof(uint8_t) * 4;
	unsigned maxElement = 0;

	void copyFrom(const ThreeMultiSet& other);
	void free();
public:
	ThreeMultiSet() = default;
	ThreeMultiSet(unsigned maxElement);
	ThreeMultiSet(const ThreeMultiSet& other);
	ThreeMultiSet& operator=(const ThreeMultiSet& other);
	~ThreeMultiSet();

	bool insert(unsigned number);
	bool remove(unsigned number);
	void clear();
	int count(int number) const;
	int count() const;
	unsigned unique() const;
	void print() const;
	int getMax() const;
	int getMin() const;
};
