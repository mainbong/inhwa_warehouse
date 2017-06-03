// 완벽한전달자 1번 복사해오세요

#include <iostream>
using namespace std;

void foo(int&& a) { cout << "foo" << endl; }

// rvalue를 rvalue로 lvalue를 lvalue로 캐스팅하는 함수
template<typename T> T&& xforward(T&& a)
{
	return static_cast<T&&>(a);
}
template<typename F, typename T> void logTime(F f, T&& a)
{
	// 아래 코드는 인자로 rvalue가 오면 : static_cast<int&&>(a)
	//				    lvalue가 오면 : static_cast<int&>(a) 

	// 즉, "인자가 rvalue라면 rvalue로 lvalue라면 lvalue로 캐스팅하는 코드입니다."
	//f(static_cast<T&&>(a));

	// T&& a 에서 10을 받으면
	// T&& : int&&
	// a   : lvalue 입니다.
	//f(xforward(a)); // a가 lvalue 이므로 xforward의 T&& => int& 

	// 그래서 반드시 명시적 추론을 사용해야 합니다.
	//f(xforward<T&&>(a));
	f(forward<T&&>(a));
}



int main()
{
	foo(10); // ok 아무 문제 없다.

	logTime(foo, 10); // ?? 왜 안될까요 ??
					  // T&& => int&& a
						// int&& r = 10; // 10은 rvalue 지만 
										// r은 lvalue 이다.
}






