#pragma once
#define SIZE 32

template<class T>
class Container
{
public:
	Container();
	~Container();
	T& operator[](unsigned i);
	unsigned Size();
private:
	unsigned size;
	T* data;
};

template<class T>
Container<T>::Container()
{
	size = SIZE;
	data = new T[size];

	for (int i = 1; i < size; i++)
		data[i - 1] = *new T;
}

template<class T>
Container<T>::~Container()
{
	delete[] data;
}

template<class T>
T& Container<T>::operator[](unsigned i)
{
	if (i >= size)
	{
		unsigned newSize = i == size ? size *= 2 : i + 1;
		T* buf = data;
		data = new T[newSize];

		for (int j = 1; j < size; j++)
			data[j - 1] = buf[j - 1];

		delete[] buf;
		size = newSize;
	}

	return data[i];
}

template<class T>
inline unsigned Container<T>::Size()
{
	return size;
}

