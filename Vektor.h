#pragma once

#include <exception>

template <typename T>
class Vektor
{
public:
	Vektor();
	Vektor(T element);
	~Vektor();

	//data managment
	void Push_back(const T& element);
	void Pop_back();
	void Insert(size_t position);
	void Erase(size_t position);
	void Push_front(T& element);
	void Pop_Front(T& Element);
	void Clear();

	//vector queries
	bool Is_Empty() const;
	size_t Size() const;
	size_t Capacity() const;
	size_t SizeOfType() const;

	//preventive mem reservation
	void Reserve(size_t size);

	//data access
	T& At(size_t position);
	T& operator[](size_t position);
	T& First();
	T& Last();

private:
	T* m_Data;
	bool m_IsEmpty;
	size_t m_Capacity;
	size_t m_Size;
	size_t m_sizeOfType;
	size_t m_FirstEmpty;

private:
	bool isInRange(size_t position);
	void Allocate(size_t newCapacity);
	void AllocWithBlank(size_t newCapacity, size_t blankIndex);
};

template<typename T>
inline Vektor<T>::Vektor() :
	m_IsEmpty(true),
	m_Capacity(2),
	m_Size(0),
	m_sizeOfType(sizeof(T)),
	m_FirstEmpty(0)
{
	Allocate(m_Capacity);
}

template<typename T>
inline Vektor<T>::Vektor(T element) :
	m_IsEmpty(false),
	m_Capacity(2),
	m_Size(1),
	m_sizeOfType(sizeof(T)),
	m_FirstEmpty(1)
{
	Allocate(m_Capacity);
	m_Data[0] = element;
}

template<typename T>
inline Vektor<T>::~Vektor()
{
	delete[] m_Data;
}

template<typename T>
inline void Vektor<T>::Push_back(const T& element)
{
	if (m_IsEmpty) 
		m_IsEmpty = false;

	if (m_Size >= m_Capacity)
	{
		size_t newCapacity = m_Capacity + m_Capacity / 2;
		Allocate(newCapacity);		
	}

	m_Data[m_FirstEmpty++] = element;
	m_Size++;
}

template<typename T>
inline void Vektor<T>::Pop_back()
{
	if (m_IsEmpty)
		return;

	m_Size--;
	m_Data[m_Size].~T();
	m_FirstEmpty--;

	if (m_FirstEmpty == 0)
		m_IsEmpty = true;
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
	if (m_Size >= m_Capacity)
	{
		size_t newCapacity = m_Capacity + m_Capacity / 2;
		AllocWithBlank(newCapacity, 0);
	}
	else
	{
		for (size_t i = m_Size; i > 0; i--)
		{
			// [ X | X | X | X | X ]
			m_Data[i] = data[i - 1];
		}
	}

	m_Data[0] = element;
	m_Size++;
}

template<typename T>
inline void Vektor<T>::Pop_Front(T& Element)
{
}

template<typename T>
inline void Vektor<T>::Clear()
{
	for (size_t i = 0; i < m_Size; i++)
		m_Data[i].~T();
	m_Size = 0;
	m_FirstEmpty = 0;
	m_IsEmpty = true;

	Allocate(2);
}

template<typename T>
inline bool Vektor<T>::Is_Empty() const
{
	return m_IsEmpty;
}

template<typename T>
inline size_t Vektor<T>::Size() const
{
	return m_Size;
}

template<typename T>
inline size_t Vektor<T>::Capacity() const
{
	return m_Capacity;
}

template<typename T>
inline size_t Vektor<T>::SizeOfType() const
{
	return m_sizeOfType;
}

template<typename T>
inline void Vektor<T>::Reserve(size_t size)
{
	Allocate(size);
}

template<typename T>
inline T& Vektor<T>::At(size_t position)
{
	if (!isInRange(position))
		exit(-1);

	return m_Data[position];
}

template<typename T>
inline T& Vektor<T>::operator[](size_t position)
{
	return m_Data[position];
}

template<typename T>
inline T& Vektor<T>::First()
{
	if (m_IsEmpty)
		exit(-1);

	return m_Data[0];
}

template<typename T>
inline T& Vektor<T>::Last()
{
	if (m_IsEmpty)
		exit(-1);

	return m_Data[m_Size - 1];
}

template<typename T>
inline bool Vektor<T>::isInRange(size_t position)
{
	return position < m_Size;
}

template<typename T>
inline void Vektor<T>::Allocate(size_t newCapacity)
{
	T* newData = new T[newCapacity];

	if (newCapacity < m_Size)
		m_Size = newCapacity;

	for (size_t i = 0; i < m_Size; i++)
	{
		newData[i] = m_Data[i];
	}

	delete[] m_Data;
	m_Data = newData;
	m_Capacity = newCapacity;
}

template<typename T>
inline void Vektor<T>::AllocWithBlank(size_t newCapacity, size_t blankIndex)
{
	T* newData = new T[newCapacity];

	if (newCapacity < m_Size)
		m_Size = newCapacity;

	size_t offset = 0;
	for (size_t i = 0; i < m_Size; i++)
	{
		if (i == blankIndex)
			offset++;

		newData[i + offset] = m_Data[i];
	}

	delete[] m_Data;
	m_Data = newData;
	m_Capacity = newCapacity;
}
