#include <iostream>
using namespace std;

// 1. ::value 로 T를 조사하는 traits
// 2. T에 변형된 타입을 알아내는 traits

template<typename T> struct xremove_reference
{
	typedef T type;
};

template<typename T> struct xremove_reference<T&>
{
	typedef T type;
};
template<typename T> struct xremove_reference<T&&>
{
	typedef T type;
};

template<typename T> void foo(T a)
{
	xremove_reference<T>::type p;
}

int main()
{
	int a = 10;
	int& r = a;
	foo(r); // 템플릿 규칙 3에 의해 int가 됩니다.

	foo<int&>(r); // 사용자가 명시했으므로 T 는 int&가 됩니다.
}





