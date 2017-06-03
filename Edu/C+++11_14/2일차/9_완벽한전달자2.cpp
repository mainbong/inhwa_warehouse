// 9_완벽한전달자 - 106page
#include <iostream>
using namespace std;

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

// 해결책 1. 함수 오버로딩 활용
// 단점. N 개 인자를 완벽하게 전달하려면 2^N 개의 logTime이 필요하다.!
template<typename F, typename T> void logTime(F f, T& a)
{
	f(a);
}
template<typename F, typename T> void logTime(F f, const T& a)
{
	f(a);
}
int main()
{
	int n = 0;

	logTime(goo, n);
	logTime(foo, 10);

	cout << n << endl; // 10나와야 한다.
}



