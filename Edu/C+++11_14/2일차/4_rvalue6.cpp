#include <iostream>
using namespace std;


struct Point { int x, y; };

Point p = { 1, 2 };
Point  foo() { return p; }

int main()
{
	int n1 = 10;

	// 규칙 1. C++ 일반 참조는 lvalue 만 참조 할수 있다.!!
	int& r1 = n1; // ok.
	//int& r2 = 10; // error
	//Point& r3 = foo(); // error


	// 규칙 2. const & 는 lvalue와 rvalue 모두 참조 할수 있다
	const int& r4 = n1; // ok.
	const int& r5 = 10; // ok.
	const Point& r6 = foo(); // ok..  이렇게 되면 임시객체의 수명이
							// r6가 살아있을때 까지로 연장된다.
							// 그리고 임시객체에 이름도 생겼다(r6)


	// 규칙 3. C++11의 && 는 rvalue만 참조 한다.
	//int&& r7 = n1; // error
	int&& r8 = 10; // ok
	Point&& r9 = foo(); // ok

}





// Annoted Reference Manual(ARM) : 왜 C++문법을 이렇게 만들었는지 설명하는 책









