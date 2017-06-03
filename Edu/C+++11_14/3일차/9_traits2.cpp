#include <iostream>
using namespace std;

// 1. ::value �� T�� �����ϴ� traits
// 2. T�� ������ Ÿ���� �˾Ƴ��� traits

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
	foo(r); // ���ø� ��Ģ 3�� ���� int�� �˴ϴ�.

	foo<int&>(r); // ����ڰ� ��������Ƿ� T �� int&�� �˴ϴ�.
}





