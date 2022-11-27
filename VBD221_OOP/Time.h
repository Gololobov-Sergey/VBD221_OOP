#pragma once
#include<iostream>

using namespace std;

class Time
{
	int hour, minute, second;

	void convert();

public:
	Time() : Time(0) { cout << "Ctor 0" << endl;  }

	Time(int s) : Time(0, s) { cout << "Ctor 1" << endl; }

	Time(int m, int s) : Time(0, m, s) { cout << "Ctor 2" << endl; }

	Time(int h, int m, int s): hour(h), minute(m), second(s) { cout << "Ctor 3" << endl; convert();}
};

void Time::convert()
{

}