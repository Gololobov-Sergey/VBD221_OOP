#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Student.h"

using namespace std;

int main()
{

	cout << Student::getNum() << endl;

	{
		Student st(30, "Vasya", 99);
		cout << Student::getNum() << endl;
		Student st2;
		cout << Student::getNum() << endl;

		st.print(); // print(st)
		st2.print();

	}
	cout << Student::getNum() << endl;
	//st.setAge(30);
	//st.setAge(3000000);
	//st.setName("Vasya");

	int a = 10.2;
	int b(10.2);
	int c{ (int)10.2 };
	


	system("pause");
}