// 완벽한전달자 1번 복사해오세요

#include <iostream>
using namespace std;

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

// 해결책 3. forward reference 사용
template<typename F, typename T> void logTime(F f, T&& a)
{
	f(a);
}

int main()
{
	int n = 0;

	logTime(foo, 10); // T&& => int&&
	logTime(goo, n);  // T&& => int& 

	cout << n << endl; // 10나와야 한다.
}



