#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Student.h"
#include"Fraction.h"
#include"Array.h"
#include"Time.h"

using namespace std;

void foo(Student st)
{
	st.print();
}

Student foo2()
{
	Student st(25, "Kolya");
	st.print();
	return st;
}

void PrintArray(MString a)
{
	a.print();
}

int main()
{
	/// 11.12.2022 //////


	// ?:  ::  sizeof  .  *

	// =
	// ++ -- -
	// + - * / % += -= *= /= %= 
	// !
	// > < == <= >= != && ||


	/*Array a(10);
	a.set();
	a.print();
	cout << a.getElemenet(5) << endl;
	cout << a[5] << endl;
	cout << a["zero"] << endl;
	int w = a[5];
	a[5] = 100;*/


	Student st(30, "Vasya");
	cout << st["name"] << endl;
	cout << st["age"] << endl;
	{
		Student st2;
		st2 = st2;
		st2.print();
	}
	st.print();

	//Fraction f0(0.5);
	//Fraction f1(1, 2);
	//Fraction f2(1, 4);
	////Fraction f3 = f1.sum(f2);
	//Fraction f3 = 5 + f1;
	////Fraction f3 = ++f1;
	////Fraction f3 = f1++;
	//f3.print();
	///*f1.print();
	//f3 += f1 + f2;
	//f3.print();

	//if (f1 && f3)
	//{

	//}*/

	////float f = f1;
	//cout << f1 << endl;
	//cin >> f1;
	//cout << f1 << endl;


	////// 04.12.2022 //////////

	//Time t(200);
	//

	//MString str4(50);
	////str4.line_filling();
	//str4.print();
	//PrintArray("wertyui");

	/*A a(-10);
	cout << a.getA() << endl;
	a.method();*/

	////// 27.11.2022 //////////

	//Time t(200);

	/*const Array a(-10);
	a.set();
	a.print();
	PrintArray(a);*/


	///*const*/ Student st(30, "Vasya");
	//st.print();
	//cout << st.getName() << endl;
	//st.getName();
	//cout << st.getName() << endl;

	//st.setName("Petyaretyuio");
	//st.print();
	//{
	//	Student st2;
	//}

	//{
	//	/*//1
	//	Student st2(st);
	//	st2.print();*/

	//	/*//2
	//	foo(st);*/


	//	////3
	//	//Student st2 = foo2();
	//	//st2.print();
	//}


	//cout << Student::getNum() << endl;

	//{
	//	Student st(30, "Vasya", 99);
	//	cout << Student::getNum() << endl;
	//	Student st2;
	//	cout << Student::getNum() << endl;

	//	st.print(); // print(st)
	//	st2.print();

	//}

	//cout << Student::getNum() << endl;
	////st.setAge(30);
	////st.setAge(3000000);
	////st.setName("Vasya");

	//int a = 10.2;
	//int b(10.2);
	//int c{ (int)10.2 };
	//

	//Fraction f1, f2;
	//Fraction f3 = f1.sum(f2);


	system("pause");
}