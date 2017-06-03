#include "show.h"

template<typename T> void foo(T a)	// int a[5] = x 될 수 없으므로
									// int* a = x 가 된다. 즉, T는 int*
{
	cout << typeid(T).name() << endl;
}

template<typename T> void goo(T& a) // int (&a)[5] = x;
{
	cout << typeid(T).name() << endl;
}

int main()
{
	int n = 10;
	double d = 3.4;
	int x[5] = { 1,2,3,4,5 };

	// T타입 에측해 보세요.
	foo(n);	// int
	foo(d);	// double
	foo(x);	// int*

	goo(x);
}