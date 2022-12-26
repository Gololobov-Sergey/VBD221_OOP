#pragma once



template<class T, class TPri = int>
struct Node
{
	T data;
	Node* next;
	TPri priority;

	Node(const T& value) : Node(value, TPri()) {}
	Node(const T& value, const TPri& priority) : data(value), priority(priority)
	{ 
		next = nullptr; 
	}
};

