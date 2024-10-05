#pragma once

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
	size_t Size() const;
	size_t Capacity() const;
	T& At(size_t position);
	const T& At(size_t position) const;
	T& operator[](size_t position) const;
	const T& operator[](size_t position) const;
	T& First() const;
	const T& First() const;
	T& Last();
	const T& Last() const;
	size_t SizeOfType() const;
	bool Is_Empty() const;
	void Reserve(size_t size);

private:
	T* m_Data;
	bool IsEmpty;
	size_t m_Capacity;
	size_t m_Lenght;
	size_t m_sizeOfType;
	size_t m_FirstEmpty;

private:
	bool isInRange(size_t position);
	T* Allocate(size_t size);
};