#pragma once
#include <iostream>

template <typename T, unsigned N>
class Stack
{
private:
	T data[N];
	size_t size = 0;
public:
	Stack() = default;

	void push(const T& obj);
	void push(T&& obj);

	void pop();

	bool isEmpty() const;

};

template<typename T, unsigned N>
void Stack<T, N>::push(const T& obj)
{
	if(size == N)
		throw std::invalid_argument("No more space in stack!");

	data[size] = obj; //operator =
	size++;
}

template<typename T, unsigned N>
void Stack<T, N>::push(T&& obj)
{
	if (size == N)
		throw std::invalid_argument("No more space in stack!");

	data[size] = std::move(obj); //move operator =
	size++;
}

template<typename T, unsigned N>
void Stack<T, N>::pop()
{
	size--;
}

template<typename T, unsigned N>
bool Stack<T, N>::isEmpty() const
{
	return size == 0;
}
