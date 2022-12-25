#pragma once

template<class T>
struct Node
{
	T data;
	Node* next;

	Node(T value) : data(value) { next = nullptr; }
};

