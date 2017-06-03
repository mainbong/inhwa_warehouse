// 12_forward
#include <iostream>
using namespace std;

// 어제 소스중 완벽한 전달자 11번..forward()복사해오세요 - 이름만 xforward로 변경하세요

template<typename T> T&& xforward(T& a) // int& & => int&
{										// int&& & => int&&

	// 즉 사용자가 lvalue 캐스팅을 요구하면 forward<int& &&>(a)
	//            rvalue 캐스팅을 요구하면 forward<int&& &&>(a) 다 됩니다.
	return static_cast<T&&>(a); // int& &&
								// int&& &&
}

template<typename F, typename T> void logTime(F f, T a)
{
	// 인자가 lvalue 이면 T는 : int&
	//        rvalue     T   : int&& 
	//						하지만 int&& a 라도 a는 _lvalue__
	f(xforward<T>(a));
}

void foo(int a) {}

int main()
{
	logTime(foo, 10);
}