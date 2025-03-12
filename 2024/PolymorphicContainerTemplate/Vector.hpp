#pragma once
#include <iostream>

template <typename T>
class Vector
{
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 8;

	void free();
	void resize(size_t newCap);
	void copyFrom(const Vector<T>&);
	void moveFrom(Vector<T>&&);

	void assertAtIndex(size_t index) const;
	void upsizeIfNeeded();
	void downsizeIfNeeded();
public:
	Vector();

	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other) noexcept;
	Vector<T>& operator=(Vector<T>&& other) noexcept;

	~Vector();

	void pushBack(const T& obj);
	void pushBack(T&& obj);

	T popBack();
	void popAt(size_t index);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t getSize() const;
	size_t getCapacity() const;

	bool isEmpty() const;
	void clear();
};

template<typename T>
inline void Vector<T>::free()
{
	delete[] data;
}

template<typename T>
inline void Vector<T>::resize(size_t newCap)
{
	T* newData = new T[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

template<typename T>
inline void Vector<T>::copyFrom(const Vector<T>& other)
{
	data = new T[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}
	size = other.size;
	capacity = other.capacity;
}

template<typename T>
inline void Vector<T>::moveFrom(Vector<T>&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity;
}

template<typename T>
inline void Vector<T>::assertAtIndex(size_t index) const
{
	if (index => size)
		throw std::exception("Out of bounds!");
}

template<typename T>
inline void Vector<T>::upsizeIfNeeded()
{
	if (size == capacity)
		resize(size * 2);
}

template<typename T>
inline void Vector<T>::downsizeIfNeeded()
{
	if (size * 2 * 2 <= capacity)
		resize(capacity / 2);
}

template<typename T>
inline Vector<T>::Vector()
{
	capacity = 4;
	size = 0;
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	free();
}

template<typename T>
inline void Vector<T>::pushBack(const T& obj)
{
	upsizeIfNeeded();

	data[size++] = obj;
}

template<typename T>
inline void Vector<T>::pushBack(T&& obj)
{
	upsizeIfNeeded();

	data[size++] = std::move(obj);
}

template<typename T>
inline T Vector<T>::popBack()
{
	downsizeIfNeeded();
	
	return data[size--];
}

template<typename T>
inline void Vector<T>::popAt(size_t index)
{
	assertAtIndex();

	for (size_t i = index; i < size; i++)
	{
		data[i] = std::move(data[i + 1]);
	}

	data[size--] = nullptr;
	downsizeIfNeeded();
}

template<typename T>
inline T& Vector<T>::operator[](size_t index)
{
	return data[index];
}

template<typename T>
inline const T& Vector<T>::operator[](size_t index) const
{
	return data[index];
}

template<typename T>
inline size_t Vector<T>::getSize() const
{
	return size;
}

template<typename T>
inline size_t Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline bool Vector<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
inline void Vector<T>::clear()
{
	size = 0;
}
