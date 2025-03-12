#include <iostream>

template <typename T>
class Polymorphic_ptr
{
private:
    T* data = nullptr;

    void free();
    void moveFrom(Polymorphic_ptr<T>&& other);
    void copyFrom(const Polymorphic_ptr<T>& other);

public:
    Polymorphic_ptr() = default;
    Polymorphic_ptr(T* obj);

    Polymorphic_ptr(const Polymorphic_ptr<T>& other);
    Polymorphic_ptr<T>& operator=(const Polymorphic_ptr<T>& other);

    Polymorphic_ptr(Polymorphic_ptr<T>&& other) noexcept;
    Polymorphic_ptr<T>& operator=(Polymorphic_ptr<T>&& other) noexcept;

    ~Polymorphic_ptr();

    const T* operator->() const;
    T* operator->();

    const T& operator*() const;
    T& operator*();

    operator bool() const;
    void reset(T* data);

    T* get();
    const T* get() const;
};
template<typename T>
void Polymorphic_ptr<T>::free()
{
    delete data;
}

template<typename T>
void Polymorphic_ptr<T>::moveFrom(Polymorphic_ptr<T>&& other)
{
    data = other.data;
    other.data = nullptr;
}

template<typename T>
void Polymorphic_ptr<T>::copyFrom(const Polymorphic_ptr<T>& other)
{
    data = other.data->clone();
}

template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(T* obj)
{
    data = obj;
}

template<typename T>
Polymorphic_ptr<T>::~Polymorphic_ptr()
{
    free();
}

template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(const Polymorphic_ptr<T>& other)
{
    copyFrom(other);
}

template<typename T>
Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(const Polymorphic_ptr<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Polymorphic_ptr<T>::Polymorphic_ptr(Polymorphic_ptr<T>&& other)
{
    moveFrom(std::move(other));
}

template<typename T>
Polymorphic_ptr<T>& Polymorphic_ptr<T>::operator=(Polymorphic_ptr<T>&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}


int main()
{
    std::cout << "Hello World!\n";
}