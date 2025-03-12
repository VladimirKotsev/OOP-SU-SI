#pragma once

template <typename T>
class Polymorphic_ptr
{
private:
	T* data;

	void free();
	void moveFrom(Polymorphic_ptr&&);
	void copyFrom(const Polymorphic_ptr& other);

public
	Polymorphic_ptr() = default;
	Polymorphic_ptr(T* obj);

	Polymorphic_ptr(const Polymorphic_ptr<T>& other);
	Polymorphic_ptr<T>& operator=(const Polymorphic_ptr<T>& other);

	Polymorphic_ptr(Polymorphic_ptr<T>&& other) noexcept;
	Polymorphic_ptr<T>& operator=(Polymorphic_ptr<T>&& other) noexcept;

	~Polymorphic_ptr();

	T* operator->();
	const T* operator->() const;

	T& operator*();
	const T& operator*() const;

	operator bool() const;
	void reset(T* data);

	T* get();
	const T* get() const;
};

template<typename T>
inline void Polymorphic_ptr<T>::free()
{
	delete data;
}

template<typename T>
inline void Polymorphic_ptr<T>::moveFrom(Polymorphic_ptr&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<typename T>
inline void Polymorphic_ptr<T>::copyFrom(const Polymorphic_ptr& other)
{
	data = other.data->clone();
}

template <typename T>
inline Polymorphic_ptr<T>::Polymorphic_ptr(T* obj)
{
	data = obj;
}

template<typename T>
inline Polymorphic_ptr<T>::Polymorphic_ptr(const Polymorphic_ptr<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(const Polymorphic_ptr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Polymorphic_ptr<T>::Polymorphic_ptr(Polymorphic_ptr<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
inline Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(Polymorphic_ptr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline Polymorphic_ptr<T>::~Polymorphic_ptr()
{
	free();
}

template<typename T>
inline T* Polymorphic_ptr<T>::operator->()
{
	return data;
}

template<typename T>
inline const T* Polymorphic_ptr<T>::operator->() const
{
	return data;
}

template<typename T>
inline T& Polymorphic_ptr<T>::operator*()
{
	if (data == nullptr)
	{
		throw std::exception("Data is null-pointer!");
	}
	return *data;
}

template<typename T>
inline const T& Polymorphic_ptr<T>::operator*() const
{
	if (data == nullptr)
	{
		throw std::exception("Data is null-pointer!");
	}
	return *data;
}

template<typename T>
inline Polymorphic_ptr<T>::operator bool() const
{
	return data != bool;
}

template<typename T>
inline void Polymorphic_ptr<T>::reset(T* data)
{
	free();
	this->data = data;
}

template<typename T>
inline T* Polymorphic_ptr<T>::get()
{
	return data;
}

template<typename T>
inline const T* Polymorphic_ptr<T>::get() const
{
	return data;
}
