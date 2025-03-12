#include <iostream>
#include <cstring>
#include <algorithm>
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
	return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

class MyString
{
private:
	char* data;
	size_t size;
	size_t capacity;

	void free();
	void moveFrom(MyString&& other);
	void copyFrom(const MyString& other);

	void resize(size_t newCapacity);

	explicit MyString(size_t stringLength);

public:
	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	const char* c_str() const;
	size_t getSize() const;
	size_t getCapacity() const;

	char& operator[](size_t index);
	const char operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	MyString& operator+=(const MyString& other);

	~MyString();

};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);

void MyString::free()
{
	delete[] data;
}

void MyString::moveFrom(MyString&& other)
{
	this->data = other.data;
	other.data = nullptr;

	this->size = other.size;
	this->capacity = other.capacity;
	other.size = 0;
	other.capacity = 0;
}

void MyString::copyFrom(const MyString& other)
{
	data = new char[other.capacity];
	capacity = other.capacity;
	size = other.size;
	strcpy(this->data, other.data);
}

void MyString::resize(size_t newCapacity)
{
	char* temp = new char[newCapacity + 1];
	strcpy(temp, data);

	capacity = newCapacity;
	delete[] data;
	this->data = temp;
}

MyString::MyString(size_t stringLength)
{
	capacity = dataToAllocByStringLen(stringLength);
	data = new char[capacity];
	size = 0;
	data[0] = '\0';
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* data)
{
	size = strlen(data + 1);
	capacity = dataToAllocByStringLen(strlen(data));
	this->data = new char[capacity];
	strcpy(this->data, data);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* MyString::c_str() const
{
	return this->data;
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

char& MyString::operator[](size_t index)
{
	return this->data[index];
}

const char MyString::operator[](size_t index) const
{
	return this->data[index];
}


std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj.c_str();
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
	char buffer[1024];
	is >> buffer;
	size_t buffStringSize = std::strlen(buffer);

	if (buffStringSize > obj.getCapacity())
		obj.resize(dataToAllocByStringLen(buffStringSize));

	strcpy(obj.data, buffer);
	obj.size = buffStringSize;
	return is;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (size + other.size > capacity)
		resize(dataToAllocByStringLen(size + other.getSize()));

	std::strncat(data, other.data, other.getSize());

	size += other.getSize();
	return *this;
}

MyString::~MyString()
{
	free();
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.getSize() + rhs.getSize());
	result += lhs;
	result += rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}