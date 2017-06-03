#include <iostream>
#include "logtime.h"
using namespace std;

void foo(int a)      { cout << "int" << endl; }
void foo(int, int a) { cout << "int, int" << endl; }

template<typename T> void goo(T a) { cout << "goo" << endl; }

int main()
{
//	foo(10);

	// logTime 사용시 주의 할점
	logTime(static_cast<void(*)(int)>(&foo), 10); // ?
	logTime(goo<int>, 10); // ?

	//printf("%p\n", foo);
	//printf("%p\n", goo); // ?
}





