#pragma once
#include<iostream>
#include<initializer_list>

using namespace std;


template<class T, size_t size>
class DynamicStack
{
	T* data = nullptr;
	size_t top = 0;

public:
	DynamicStack();
	DynamicStack(initializer_list<T> list);
	DynamicStack(const DynamicStack& stack);
	DynamicStack& operator=(const DynamicStack& stack);
	~DynamicStack();
	void push(const T& value);
	const T& peek() const;
	void pop();
	size_t length() const;
	bool isFull() const;
	bool isEmpty() const;
	void clear();
	void print() const;
};

