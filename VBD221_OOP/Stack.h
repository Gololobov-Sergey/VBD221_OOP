#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>
#include"Node.h"

using namespace std;


template<class T, size_t maxSize>
class Stack
{
	Node<T>* first = nullptr;
	size_t size = 0;

public:
	Stack();
	Stack(initializer_list<T> list);
	Stack(const Stack& stack);
	Stack& operator=(const Stack& stack);
	~Stack();
	void push(const T& value);
	const T& peek() const;
	void pop();
	size_t length() const;
	bool isFull() const;
	bool isEmpty() const;
	void clear();
	void print() const;
};

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack()
{
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push(elem);
	}
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& stack)
{
	Node<T>* temp1 = stack.first;
	this->first = new Node<T>(stack.first->data);
	Node<T>* temp2 = this->first;
	while (temp1->next)
	{
		temp2->next = new Node<T>(temp1->next->data);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	this->size = stack.size;

}

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	this->clear();
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::push(const T& value)
{
	if (size < maxSize)
	{
		if (size == 0)
		{
			first = new Node<T>(value);
			//first->data = value;
		}
		else
		{
			Node<T>* temp = new Node<T>(value);
			temp->next = first;
			first = temp;
		}
		size++;
	}
}

template<class T, size_t maxSize>
const T& Stack<T, maxSize>::peek() const
{
	assert(size > 0);
	return first->data;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::length() const
{
	return size;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isFull() const
{
	return size == maxSize;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
{
	//1
	//while (size)
	//	pop();


	//2
	Node<T>* temp = first;
	while (first)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
