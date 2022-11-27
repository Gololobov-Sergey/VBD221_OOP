#pragma once
#include<iostream>

using namespace std;

class Student
{
	const int id;
	int age = 0;
	char* name;
	static int num;


	void foo()
	{

	}

public:

	

	Student() : age(0), id(++num)
	{
		name = new char[8];
		strcpy(name, "No name");
		cout << "Constructor" << endl;
		foo();
	}

	Student(int age, const char* n, int id) : age(age), id(++num)
	{
		this->name = new char[strlen(n) + 1];
		strcpy(this->name, n);
		cout << "Constructor 2 param" << endl;
	}

	~Student()
	{
		num--;
		delete name;
		cout << "Destructor" << endl;
	}

	int getAge();

	char* getName()
	{
		return name;
	}

	void setAge(int a)
	{
		if (a < 0 || a > 120)
			return;
		age = a;
	}

	void setName(const char* n)
	{
		strcpy(name, n);
	}

	void print();

	Student method()
	{
		//
		return *this;
	}

	static int getNum()
	{
		return num;
	}

	static void setNum(int n)
	{
		num = n;
	}
};

int Student::num = 0;


int Student::getAge()
{
	return age;
}

void Student::print()
{
	cout << "Name: " << name << ", Age: " << age << endl;
}