#include <iostream>
using namespace std;

// ref()사용예제
void foo()       { cout << "foo" << endl; }
void goo(int& a) { a = 10; }

// C++11표준이 제공하는 범용적 함수포인터 역활의 객체
#include <functional>

int main()
{
	function<void()> f = &foo;
	f(); // foo 호출!!

	int n = 0;

	f = bind(&goo, ref(n) ); // goo의 인자를 n으로 고정
	f(); // goo(n)

	cout << n << endl; // 10 나와야 합니다!
}






/*
int main()
{
	void(*f1)() = &foo; 

	f1 = &goo; // ?
}
*/