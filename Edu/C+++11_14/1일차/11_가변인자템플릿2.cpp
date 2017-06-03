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
	// args : Parameter Pack 이라고 부릅니다.

	// 1. 갯수 알아 내기
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

	// 2. Parameter Pack를 다른 함수로 전달하기
	//   "Pack Expansion"
	foo(args...); // ...에 주의!
	hoo(args...);
	joo(&args...);
}




int main()
{
	goo(1, 2.2, 'a'); // Types : int, double, char
					  // args  : 1, 2.2, 'a'
}