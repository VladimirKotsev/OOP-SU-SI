#pragma once

template <typename T>
class Vector
{
private:
	T* array;
	size_t capacity = 8;
	size_t size = 0;
	
	size_t getIndex = 0;
	size_t putIndex() const;

	void moveFrom(Vector<T>&& other);
	void copyFrom(const Vector<T>& other);
	void free();

	void resize(size_t newCapacity);
public:
	Vector();

	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other);
	Vector<T>& operator=(Vector<T>&& other);

	void push_back(const T& obj);
	void push_back(T&& obj);

	void pop_back();

	void insert(const T& obj, size_t index);
	void insert(T&& obj, size_t index);

	void erase(size_t index);

	void clear();

	~Vector();
};

template<typename T>
size_t Vector<T>::putIndex() const
{
	return (getIndex + 1);
}

template<typename T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	this->array = other->array;
	other.array = nullptr;

	this->capacity = other.capacity;
	this->size = other.size;
	other.capacity = 8;
	other.size = 0;

	this->getIndex = other.getIndex;
	other.getIndex = 0;
}

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	free();
	this->array = new T[other.capacity];
	this->array = other.array;
	this->size = other.size;
	this->capacity = other.capacity;
	this->getIndex = other.getIndex;
}

template<typename T>
void Vector<T>::free()
{
	delete[] this->array;
	this->capacity = 8;
	this->getIndex = 0;
	this->size = 0;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity)
{

}

template<typename T>
Vector<T>::Vector() : capacity(8), size(0)
{
	array = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != *other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
	if (this != *other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
void Vector<T>::push_back(const T& obj)
{
	if (size + 1 > capacity)
		resize(capacity * 2);

	this->array[putIndex()] = obj;
	size++;
	getIndex++;
}

template<typename T>
void Vector<T>::push_back(T&& obj)
{
	if (size + 1 > capacity)
		resize(capacity * 2);

	array[putIndex()] = std::move(obj); //move operator =
	size++;
	getIndex++;
}

template<typename T>
void Vector<T>::pop_back()
{
	size--;
	getIndex--;
}

template<typename T>
void Vector<T>::insert(const T& obj, size_t index)
{
	if (size + 1 > capacity)
		resize(capacity * 2);

	//shift right
	for (size_t i = size + 1; i > index; i--)
	{
		array[i] = array[i - 1];
	}

	array[index] = obj;
	getIndex++;
	size++;
}

template<typename T>
void Vector<T>::insert(T&& obj, size_t index)
{
	if (size + 1 > capacity)
		resize(capacity * 2);

	//shift right
	for (size_t i = size + 1; i > index; i--)
	{
		array[i] = array[i - 1];
	}

	array[index] = std::move(obj); // move operator=
	getIndex++;
	size++;
}

template<typename T>
void Vector<T>::erase(size_t index)
{
	//shift left
	for (size_t i = index; i < size; i++)
	{
		array[i] = array[i + 1];
	}

	size--;
	getIndex--;
}

template<typename T>
void Vector<T>::clear()
{
	free();
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

