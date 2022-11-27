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

	Student() : Student(0, "Noname")
	{
		//name = nullptr;
		/*name = new char[8];
		strcpy(name, "No name");*/
		cout << "Constructor" << endl;
		foo();
	}

	Student(int age, const char* n) : age(age), id(++num)
	{
		this->name = new char[strlen(n) + 1];
		strcpy(this->name, n);
		cout << "Constructor 2 param" << endl;
	}

	Student(const Student& obj) : id(++num)
	{
		age = obj.age;
		name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
		cout << "Constructor copy" << endl;
	}

	~Student()
	{
		num--;
		delete name;
		cout << "Destructor" << endl;
	}

	int getAge() const;

	const char* getName() const
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
		delete name;
		this->name = new char[strlen(n) + 1];
		strcpy(this->name, n);
	}

	void print() const;

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


int Student::getAge() const
{
	return age;
}

void Student::print() const
{
	cout << "Name: " << name << ", Age: " << age << endl;
}