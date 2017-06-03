#include "show.h"

using namespace std::placeholders; // _1, _2, _3...

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

// 이 소스가 바인더의 핵심입니다.
int main()
{
	modulus<int> m;

	cout << m(10, 3) << endl;

	// bind1st(), bind2nd() : 이항함수 객체를 단항 함수객체로..
	//							C++11에서 deprecated
	cout << bind2nd(m, 3)(10) << endl; // 10 % 3
	cout << bind1st(m, 3)(2) << endl; // 3 % 2

	// C++11 bind() : 함수객체 뿐 아니라.. 일반 함수도
	//					M 항을 N 항으로
	cout << bind(m, _1, 5)(10) << endl; // m(10, 5) 10 % 5

	cout << bind(m, 10, _1)(3) << endl; // 10 % 3

	cout << bind(m, 10, 3)() << endl; // 10 % 3

	bind(&foo, 3, _2, 2, _1)(9, 7);
}
