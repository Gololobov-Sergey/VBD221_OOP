#pragma once
#include<iostream>
#include<initializer_list>

using namespace std;


template<class T, size_t size>
class StaticStack
{
	T data[size] = {T()};
	size_t top = 0;

public:
	StaticStack();
	StaticStack(initializer_list<T> list);
	void push(const T& value);
	const T& peek() const;
	void pop();
	size_t length() const;
	bool isFull() const;
	bool isEmpty() const;
	void clear();
	void print() const;
};

template<class T, size_t size>
StaticStack<T, size>::StaticStack()
{
}

template<class T, size_t size>
StaticStack<T, size>::StaticStack(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push(elem);
	}
}

template<class T, size_t size>
void StaticStack<T, size>::push(const T& value)
{
	if (top < size)
	{
		data[top++] = value;
	}
}

template<class T, size_t size>
const T& StaticStack<T, size>::peek() const
{
	if (top > 0)
	{
		return data[top - 1];
	}
}

template<class T, size_t size>
void StaticStack<T, size>::pop()
{
	if (top > 0)
	{
		top--;
	}
}

template<class T, size_t size>
size_t StaticStack<T, size>::length() const
{
	return top;
}

template<class T, size_t size>
inline bool StaticStack<T, size>::isFull() const
{
	return top == size;
}

template<class T, size_t size>
inline bool StaticStack<T, size>::isEmpty() const
{
	return top == 0;
}

template<class T, size_t size>
inline void StaticStack<T, size>::clear()
{
	top = 0;
}

template<class T, size_t size>
void StaticStack<T, size>::print() const
{
	for (size_t i = 0; i < top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

