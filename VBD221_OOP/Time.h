#pragma once
#include<iostream>

using namespace std;

class Date;

class ShowTime;

class Time
{
	int hour, minute, second;

	void convert();

public:
	Time() : Time(0) { cout << "Ctor 0" << endl;  }

	Time(int s) : Time(0, s) { cout << "Ctor 1" << endl; }

	Time(int m, int s) : Time(0, m, s) { cout << "Ctor 2" << endl; }

	Time(int h, int m, int s): hour(h), minute(m), second(s) { cout << "Ctor 3" << endl; convert();}

	friend void print(Time t);

	friend void printDateTime(Date d, Time t);

	friend class ShowTime;

	void method(ShowTime sht);

	//friend void ShowTime::show1(Time t);
};

void Time::convert()
{

}

void print(Time t)
{
	cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}


class ShowTime
{
	int tttt;
public:
	void show1(Time t);
	void show2(Time t);
	void show3(Time t);

	friend class Time;
};

void ShowTime::show1(Time t)
{
	t.hour;
}


void ShowTime::show2(Time t)
{
	t.minute;
}


void Time::method(ShowTime sht)
{
	sht.tttt;
}

class Date
{
	int d;

public:
	Date(int d) : d(d)
	{

	}

	friend void printDateTime(Date d, Time t);

};


void printDateTime(Date d, Time t)
{
	
}


enum class Color
{
	Black, Red
};

enum class Animal
{
	Cat, Dog
};

class A
{
	class B
	{
		int b;

	public:
		B(int b) :b(b) {}
		int getB() { return b; }
	};

	B b;
	Color color = Color::Black;

public:

	A(int a) : b(a) {}
	int getA() { return b.getB(); }
	void method()
	{
		if (color == Color::Black)
		{
			cout << "Color Cat" << endl;
		}
	}
};