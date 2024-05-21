#pragma once

#include <iostream>

template <typename T>
class MyQueue
{
private:
	T* data;
	size_t size;
	size_t capacity;

	size_t getIndex;
	size_t putIndex;

	void free();
	void copyFrom(const MyQueue<T>& other);
	void moveFrom(MyQueue<T>&& other);

	void resize();
public:
	MyQueue();

	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	MyQueue(MyQueue<T>&& other);
	MyQueue<T>& operator=(MyQueue<T>&& other);

	void push(const T& obj);
	void push(T&& obj);

	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~MyQueue();
};

template<typename T>
void MyQueue<T>::free()
{
	delete[] data;
}

template<typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	this->data = new T[other.capacity];
	for (size_t i = 0; i < other.capacity; i++)
		this->data[i] = other.data[i];

	this->capacity = other.capacity;
	this->size = other.size;

	this->getIndex = other.getIndex;
	this->putIndex = other.putIndex;
}

template<typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	this->data = other.data;
	other.data = nullptr;

	this->capacity = other.capacity;
	this->size = other.size;

	this->getIndex = other.getIndex;
	this->putIndex = other.putIndex;

	other.getIndex = other.putIndex = other.capacity = other.size = 0;
}

template<typename T>
void MyQueue<T>::resize()
{
	T* temp = new T[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[getIndex];
		(++getIndex) %= capacity;
	}

	delete[] data;
	capacity *= 2;
	getIndex = 0;
	putIndex = size;
	data = temp;
}

template<typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	data = new T[capacity];

	size = 0;
	getIndex = 0;
	putIndex = 0;
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
void MyQueue<T>::push(const T& obj)
{
	if(size == capacity)
		resize(capacity * 2);

	(++putIndex) %= capacity;

	data[putIndex] = obj; //operator=
	size++;
}

template<typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity)
		resize(capacity * 2);

	(++putIndex) %= capacity;

	data[putIndex] = std::move(obj); //move operator=
	size++;
}

template<typename T>
void MyQueue<T>::pop()
{
	if (size == 0)
		throw std::invalid_argument("Queue is empty!");

	(++getIndex) %= capacity;
	size--;
}

template<typename T>
const T& MyQueue<T>::peek() const
{
	return data[getIndex];
}

template<typename T>
bool MyQueue<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	free();
}