#include <iostream>
using namespace std;

void foo(int a)        { cout << "foo" << endl; }
void goo(int a, int b) { cout << "goo" << endl; }
void hoo()				{ cout << "hoo" << endl; }

// 함수의 성능 측정을 위한 logTime()를 다시 생각해 봅시다.

// 완벽한 전달자(perfect forwarding) : 함수의 인자를 받아서 다른 함수로 전달하는
//								래퍼를 만들때, 인자를 몇개라도 완벽하게 전달하게
//								만드는 기술(항목 2-19에서 자세히 소개)
template<typename F, typename ... Types> 
void logTime(F f, Types ... args)
{
	f(args...); // ... 에 주의
}

int main()
{
	logTime(foo, 10);
	logTime(goo, 10, 20);
	logTime(hoo);
}







