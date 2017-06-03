// 9_완벽한전달자 - 106page
#include <iostream>
using namespace std;

// perfect forwarding : 래퍼 함수(클래스)를 만들때 인자를 완벽하게 전달하는기술

int foo(int a) { cout << "foo" << endl; return 100; }
void goo(int& a) { cout << "goo" << endl; a = 10; }
// webkit/webkit/Source/WTF/WTF/NeverDestroyed.h 열어 보세요


// 완벽한 전달자가 되려면
// 1. 인자를 Universal(forward) reference 사용
// 2. 원래 함수로 보낼때 인자를 다시 _forward_ 로 묶어서 전달
// 3. forward<T&&> 방식의 명시적 추론사용
// 4. 가변인자 템플릿으로!!
template<typename F, typename ... Types> 
auto logTime(F f, Types&& ... args) 
{
	//f(forward<Types&&>(args...)); // error
	//return f(forward<Types&&>(args)...); // ok..
	return f(forward<Types>(args)...); // ok..
}


int main()
{
	int n = 0;
	int x = logTime(foo, 10);

	cout << x << endl;
	logTime(goo, n);

	cout << n << endl;
}



