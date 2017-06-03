#include <iostream>
using namespace std;

struct Plus
{
	// 대부분 함수객체의 () 연산자 함수는 상수 함수로 만드는 것이
	// 좋습니다. 아래 foo()를 생각해 보세요!!
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

template<typename T> void foo(const T& a)
{
	// a는 상수 객체가 된다.
	// 상수 객체는 상수 함수만 호출할수 있다 - C++ 기본 문법책 참고
	int n = a(1, 2);
}


int main()
{
	Plus p;
	
	foo(p);
}




