
#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T, int s = 10>
class Array
{
	T* arr;
	size_t size;

public:
	Array() : Array(0) { }

	explicit Array(size_t s = 10)
	{
		/*assert(s > 0);
		size = s;
		arr = new int[size];*/
		size = (s > 0) ? s : 0;
		arr = (s > 0) ? new T[size] : nullptr;
	}

	~Array()
	{
		delete[]arr;
	}

	Array(const Array& obj)
	{
		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	void set(int min = 0, int max = 9) const
	{
		//if (strcmp(typeid(T).name(), "int") == 0)
		//{
		//	cout << typeid(T).name() << endl;
		//}
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	T getElemenet(size_t index)
	{
		assert(index < size);
		return arr[index];
	}

	T& operator[](size_t index)
	{
		assert(index < size);
		return arr[index];
	}

	T& operator[](const char* key)
	{
		if (strcmp(key, "zero") == 0)
			return arr[0];
		if (strcmp(key, "one") == 0)
			return arr[1];
		if (strcmp(key, "two") == 0)
			return arr[2];
		if (strcmp(key, "tree") == 0)
			return arr[3];
	}

	size_t length(){return size;}

	void method();
};

template<class T, int s>
void Array<T, s>::method()
{

}


template<>
void Array<Fraction>::set(int min, int max) const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = Fraction(rand() % (max - min + 1) + min, rand() % (max - min + 1) + min);
	}
}


template<>
void Array<double>::set(int min, int max) const
{
	for (size_t i = 0; i < size; i++)
	{
		double d = 1.0 / (rand() % 10);
		arr[i] = rand() % (max - min + 1) + min + d;
	}
}

template<class T, int size> // non type parametr
class StaticArray
{
	T arr[size];

public:
	StaticArray() {}
	int getSize() { return size; }
};