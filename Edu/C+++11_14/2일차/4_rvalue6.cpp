#include <iostream>
using namespace std;


struct Point { int x, y; };

Point p = { 1, 2 };
Point  foo() { return p; }

int main()
{
	int n1 = 10;

	// ��Ģ 1. C++ �Ϲ� ������ lvalue �� ���� �Ҽ� �ִ�.!!
	int& r1 = n1; // ok.
	//int& r2 = 10; // error
	//Point& r3 = foo(); // error


	// ��Ģ 2. const & �� lvalue�� rvalue ��� ���� �Ҽ� �ִ�
	const int& r4 = n1; // ok.
	const int& r5 = 10; // ok.
	const Point& r6 = foo(); // ok..  �̷��� �Ǹ� �ӽð�ü�� ������
							// r6�� ��������� ������ ����ȴ�.
							// �׸��� �ӽð�ü�� �̸��� �����(r6)


	// ��Ģ 3. C++11�� && �� rvalue�� ���� �Ѵ�.
	//int&& r7 = n1; // error
	int&& r8 = 10; // ok
	Point&& r9 = foo(); // ok

}





// Annoted Reference Manual(ARM) : �� C++������ �̷��� ��������� �����ϴ� å









