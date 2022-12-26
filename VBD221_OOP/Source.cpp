#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Student.h"
#include"Fraction.h"
#include"Array.h"
#include"Time.h"
#include"StaticStack.h"
#include"Stack.h"
#include"Function.h"
#include"Queue.h"

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

enum class DEPARTMENT
{
	DIRECTOR = 3, BUCH = 2, TRANSPORT = 1
};

ostream& operator<<(ostream& out, const DEPARTMENT& f)
{
	switch (f)
	{
	case DEPARTMENT::DIRECTOR:
		out << "DIRECTOR"; break;
	case DEPARTMENT::BUCH:
		out << "BUCH"; break;
	case DEPARTMENT::TRANSPORT:
		out << "TRANSPORT"; break;

	}return out;
}

int main()
{

	/*int i = 0;
	while (true)
	{
		gotoxy(10, 10);
		cout << ++i;
		Sleep(1000);
		gotoxy(10, 10);
		cout << "    ";
	}*/




	PriorityQueue<int, DEPARTMENT> q;
	q.enqueue(10, DEPARTMENT::DIRECTOR);
	q.enqueue(20, DEPARTMENT::BUCH);
	q.enqueue(30, DEPARTMENT::TRANSPORT);
	q.enqueue(40, DEPARTMENT::DIRECTOR);
	q.enqueue(50, DEPARTMENT::BUCH);
	q.print();

	/*Queue<int> q = {1,4,6};
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.print();
	q.dequeue();
	q.dequeue();
	q.print();
	q.enqueue(80);
	q.enqueue(90);
	q.ring();
	q.ring();
	q.print();*/


	//Stack<int, 10> stack = {1,23};
	/*int m = stack.peek();
	cout << m << endl;*/
	/*stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
	stack.clear();
	stack.print();*/
	
	/*Stack<int, 10> st2(stack);
	st2.print();*/
	
	/*char buff[] = "3+2*3+5";
	Calc c;
	int res = c("3+2*3+5");*/

	/*char buff[] = "{()[(){[](})[]}()[]]{}}";
	Stack<char, 40> s;
	int pos = 0;
	for (size_t i = 0; buff[i] != '\0'; i++)
	{
		switch (buff[i])
		{
		case '(': case '[': case '{': s.push(buff[i]); break;
		}

		switch (buff[i])
		{
		case ')': 
			if (s.peek() == '(')
				s.pop();
			else
				pos = i;
			break;
		case ']': 
			if (s.peek() == '[')
				s.pop();
			else
				pos = i;
			break;
		case '}': 
			if (s.peek() == '{')
				s.pop();
			else
				pos = i;
			break;
		}
		if (pos != 0)
			break;
	}

	cout << ((s.isEmpty()) ? "Balance" : "Not balance") << endl;
	if (pos != 0)
	{
		for (size_t i = 0; i < strlen(buff); i++)
		{
			SetColor((i == pos) ? LightRed : LightGray, Black);
			cout << buff[i];
		}
		cout << endl;
	}*/

	/*Array<Fraction, 20> a(10);
	a.set();
	a.print();

	const int s = 10;
	StaticArray<int, s> arr;
	cout << arr.getSize() << endl;*/



	/// 11.12.2022 //////


	// ?:  ::  sizeof  .  *

	// =
	// ++ -- -
	// + - * / % += -= *= /= %= 
	// !
	// > < == <= >= != && ||
	// () []
	// <=>

	/*Array a(10);
	a.set();
	a.print();
	cout << a.getElemenet(5) << endl;
	cout << a[5] << endl;
	cout << a["zero"] << endl;
	int w = a[5];
	a[5] = 100;*/

	/*Time t;
	Time t2 = ++t;
	t2 = t2 + ++t;*/


	/*Student st(30, "Vasya");
	cout << st["name"] << endl;
	cout << st["age"] << endl;
	{
		Student st2;
		st2 = st2;
		st2.print();
	}
	st.print();*/

	//Fraction f0(0.5);
	//Fraction f1(1, 2);
	//f1(2, 5);
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