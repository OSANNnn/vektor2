#include "Vektor.h"


template<typename T>
Vektor<T>::Vektor() :
	IsEmpty(true),
	m_Capacity(1),
	m_Lenght(0),
	m_sizeOfType(0),
	m_FirstEmpty(0)
{
	m_Data = new T[];
}

template<typename T>
Vektor<T>::Vektor(T element)
{
}

template<typename T>
Vektor<T>::~Vektor()
{
}

template<typename T>
void Vektor<T>::Push_back(T& element)
{
}

template<typename T>
void Vektor<T>::Pop_back()
{
}

template<typename T>
void Vektor<T>::Insert(size_t position)
{
}

template<typename T>
void Vektor<T>::Erase(size_t position)
{
}

template<typename T>
void Vektor<T>::Push_front(T& element)
{
}

template<typename T>
void Vektor<T>::Pop_Front(T& Element)
{
}

template<typename T>
void Vektor<T>::Clear()
{
}

template<typename T>
size_t Vektor<T>::Size() const
{
	return size_t();
}

template<typename T>
size_t Vektor<T>::Capacity() const
{
	return size_t();
}

template<typename T>
T& Vektor<T>::At(size_t position)
{
	// TODO: insert return statement here
}

template<typename T>
const T& Vektor<T>::At(size_t position) const
{
	// TODO: insert return statement here
}

template<typename T>
T& Vektor<T>::operator[](size_t position) const
{
	// TODO: insert return statement here
}

template<typename T>
T& Vektor<T>::First() const
{
	// TODO: insert return statement here
}

template<typename T>
T& Vektor<T>::Last()
{
	// TODO: insert return statement here
}

template<typename T>
const T& Vektor<T>::Last() const
{
	// TODO: insert return statement here
}

template<typename T>
size_t Vektor<T>::SizeOfType() const
{
	return size_t();
}

template<typename T>
bool Vektor<T>::Is_Empty() const
{
	return false;
}

template<typename T>
void Vektor<T>::Reserve(size_t size)
{
}

template<typename T>
bool Vektor<T>::isInRange(size_t position)
{
	return false;
}

template<typename T>
T* Vektor<T>::Allocate(size_t size)
{
	return nullptr;
}
