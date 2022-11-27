
#pragma once
#include<iostream>
#include<cassert>

using namespace std;


class Array
{
	int* arr;
	int size;

public:
	Array() : Array(0) { }

	explicit Array(int s)
	{
		/*assert(s > 0);
		size = s;
		arr = new int[size];*/
		size = (s > 0) ? s : 0;
		arr = (s > 0) ? new int[size] : nullptr;
	}

	~Array()
	{
		delete[]arr;
	}

	Array(const Array& obj)
	{
		size = obj.size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	void set() const
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
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
};
