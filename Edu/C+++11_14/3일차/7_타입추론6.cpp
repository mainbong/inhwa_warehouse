// 타입추론6. auto와 타입 추론 - 98 page
#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

// auto : template 추론과 동일한 규칙 사용 - 98 page
// T    param     foo( expr )
// auto param =        r;

int main()
{
	auto n1 = foo(); // n1은 int
	n1 = 20; // x는 변하지 않는다.

	decltype(foo()) n2 = foo(); // n2는 int&

	// C++14에서 새롭게 나온 코드
	decltype(auto) n3 = foo(); // 우변으로타입을 결정하는데
								// 추론 규칙은 decltype 규칙으로!

	// decltype에서 조심할점.
	int n4 = 10;
	int* p = &n4;
	decltype(*p) n5 = n4; // 무슨 타입일까요 int&
}




/*
int main()
{
	int  n = 10;
	int& r = n;

	auto  a = r; // a는 int 
	auto& a1 = r; // a1은 int&

	decltype(r) d2 = r; // int&

	a = 20;
	cout << r << endl; // 10 ? 20
}
*/





