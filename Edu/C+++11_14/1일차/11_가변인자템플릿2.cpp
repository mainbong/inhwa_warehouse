#include <iostream>
using namespace std;

template<typename ... Types> void foo(Types ... args)
{
	cout << "foo" << endl;
}

void hoo(int a, double d, char c) { cout << "hoo" << endl; }
void joo(int* a, double* d, char* c) { cout << "joo" << endl; }

template<typename ... Types> void goo(Types ... args)
{
	// args : Parameter Pack �̶�� �θ��ϴ�.

	// 1. ���� �˾� ����
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

	// 2. Parameter Pack�� �ٸ� �Լ��� �����ϱ�
	//   "Pack Expansion"
	foo(args...); // ...�� ����!
	hoo(args...);
	joo(&args...);
}




int main()
{
	goo(1, 2.2, 'a'); // Types : int, double, char
					  // args  : 1, 2.2, 'a'
}