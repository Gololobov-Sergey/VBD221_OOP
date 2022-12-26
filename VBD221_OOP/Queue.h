#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>
#include"Node.h"

using namespace std;

template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

public:
	Queue();
	Queue(initializer_list<T> list);
	Queue(const Queue& q);
	Queue& operator=(const Queue& q);
	~Queue();
	void enqueue(const T& value);
	void dequeue();
	const T& peek() const;
	size_t length() const;
	bool isEmpty() const;
	void clear();
	void print() const;
	void ring();
};

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T>
Queue<T>::Queue(const Queue& q)
{
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
Queue<T>::~Queue()
{
	this->clear();
}

template<class T>
void Queue<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		last = first = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;
	}
}

template<class T>
const T& Queue<T>::peek() const
{
	assert(size > 0);
	return first->data;
}

template<class T>
inline size_t Queue<T>::length() const
{
	return size;
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void Queue<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
}

template<class T>
void Queue<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::ring()
{
	if (size > 1)
	{
		Node<T>* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		last->next = nullptr;
	}
}


//////////////// PriorityQueue  /////////////

template<class T, class TPri = int>
class PriorityQueue
{
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t   size = 0;

public:
	PriorityQueue();
	PriorityQueue(initializer_list<T> list);
	PriorityQueue(const PriorityQueue& q);
	PriorityQueue& operator=(const PriorityQueue& q);
	~PriorityQueue();
	void enqueue(const T& value, const TPri& pri);
	void dequeue();
	const T& peek() const;
	size_t length() const;
	bool isEmpty() const;
	void clear();
	void print() const;
};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem, TPri());
	}
}

template<class T, class TPri>
inline PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& q)
{
}

template<class T, class TPri>
inline PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& q)
{
	// TODO: вставьте здесь оператор return
}

template<class T, class TPri>
inline PriorityQueue<T, TPri>::~PriorityQueue()
{
	this->clear();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, const TPri& pri)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, pri);
	if (size == 0)
	{
		last = first = newNode;
		size++;
		return;
	}

	if (pri <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else if (pri > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (pri <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;
	}
}

template<class T, class TPri>
const T& PriorityQueue<T, TPri>::peek() const
{
	assert(size > 0);
	return first->data;
}

template<class T, class TPri>
inline size_t PriorityQueue<T, TPri>::length() const
{
	return size;
}

template<class T, class TPri>
inline bool PriorityQueue<T, TPri>::isEmpty() const
{
	return size == 0;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->priority << ":" << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
