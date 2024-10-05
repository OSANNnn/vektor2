#pragma once

#include <memory>

template <typename T>
class Vektor
{
public:
	Vektor();
	Vektor(T element);
	~Vektor();

	void Push_back(T& element);
	void Pop_back();
	void Insert(size_t position);
	void Erase(size_t position);
	void Push_front(T& element);
	void Pop_Front(T& Element);
	void Clear();

	bool Is_Empty() const;
	size_t Size() const;
	size_t Capacity() const;
	size_t SizeOfType() const;
	void Reserve(size_t size);

	T& At(size_t position);
	const T& At(size_t position) const;
	T& operator[](size_t position);
	const T& operator[](size_t position) const;
	T& First();
	const T& First() const;
	T& Last();
	const T& Last() const;

private:
	T* m_Data;
	bool m_IsEmpty;
	size_t m_Capacity;
	size_t m_Lenght;
	size_t m_sizeOfType;
	size_t m_FirstEmpty;

private:
	bool isInRange(size_t position);
	T* Allocate(size_t size);
};

template<typename T>
Vektor<T>::Vektor() :
	m_IsEmpty(true),
	m_Capacity(2),
	m_Lenght(0),
	m_sizeOfType(sizeof(T)),
	m_FirstEmpty(0)
{
	m_Data = Allocate(m_Capacity);
}

template<typename T>
inline Vektor<T>::Vektor(T element) :
	m_IsEmpty(false),
	m_Capacity(2),
	m_Lenght(1),
	m_sizeOfType(sizeof(T)),
	m_FirstEmpty(1)
{
	m_Data = Allocate(m_Capacity);
	m_Data[0] = element;
}

template<typename T>
inline Vektor<T>::~Vektor()
{
	delete[] m_Data;
}

template<typename T>
inline void Vektor<T>::Push_back(T& element)
{
	if (m_IsEmpty) 
		m_IsEmpty = false;

	if (m_Capacity - m_Lenght == 0)
	{
		float newCapacity = m_Capacity + (float)m_Capacity / 2;
		m_Capacity = (size_t)newCapacity;
		T* newData = Allocate(m_Capacity);

		memcpy(newData, m_Data, m_Lenght * m_sizeOfType);
		delete[] m_Data;
		m_Data = newData;
	}

	m_Data[m_FirstEmpty++] = element;
	m_Lenght++;
}

template<typename T>
inline void Vektor<T>::Pop_back()
{
}

template<typename T>
inline void Vektor<T>::Insert(size_t position)
{
}

template<typename T>
inline void Vektor<T>::Erase(size_t position)
{
}

template<typename T>
inline void Vektor<T>::Push_front(T& element)
{
}

template<typename T>
inline void Vektor<T>::Pop_Front(T& Element)
{
}

template<typename T>
inline void Vektor<T>::Clear()
{
}

template<typename T>
inline bool Vektor<T>::Is_Empty() const
{
	return m_IsEmpty;
}

template<typename T>
inline size_t Vektor<T>::Size() const
{
	return size_t();
}

template<typename T>
inline size_t Vektor<T>::Capacity() const
{
	return size_t();
}

template<typename T>
inline size_t Vektor<T>::SizeOfType() const
{
	return size_t();
}

template<typename T>
inline void Vektor<T>::Reserve(size_t size)
{
}

template<typename T>
inline T& Vektor<T>::At(size_t position)
{
	// TODO: insert return statement here
}

template<typename T>
inline const T& Vektor<T>::At(size_t position) const
{
	// TODO: insert return statement here
}

template<typename T>
inline T& Vektor<T>::operator[](size_t position)
{
	// TODO: insert return statement here
}

template<typename T>
inline const T& Vektor<T>::operator[](size_t position) const
{
	// TODO: insert return statement here
}

template<typename T>
inline T& Vektor<T>::First()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T& Vektor<T>::First() const
{
	// TODO: insert return statement here
}

template<typename T>
inline T& Vektor<T>::Last()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T& Vektor<T>::Last() const
{
	// TODO: insert return statement here
}

template<typename T>
inline bool Vektor<T>::isInRange(size_t position)
{
	return false;
}

template<typename T>
inline T* Vektor<T>::Allocate(size_t size)
{
	return new T[size];
}
