#pragma once
#include "Vector.hpp"
#include "Polymorphic_ptr.hpp"

template <typename T>
class Polymorphic_container
{
	Vector<Polymorphic_ptr<T>> data;

public:
	void add(T* obj);

	void execute(size_t index, void(*func)(T*));
	void execute(size_t index, void(*func)(const T*)) const;

};

template<typename T>
void Polymorphic_container<T>::add(T* ptr)
{
	ptrs.push_back(ptr);
}

template<typename T>
void Polymorphic_container<T>::execute(size_t index, void(*func)(T*))
{
	func(ptrs[index].get());
}

template<typename T>
void Polymorphic_container<T>::execute(size_t index, void(*func)(const T*)) const
{
	func(ptrs[index].get());
}