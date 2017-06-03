#include <iostream>
using namespace std;

// 레퍼런스와 함수 오버로딩 규칙
void foo(int& a)       { cout << "int&" << endl; }		// 1
void foo(const int& a) { cout << "const int&" << endl; }// 2
void foo(int&& a)	   { cout << "int&&" << endl; }		// 3

int main()
{
	int n = 10;
//	foo(n); // 1번 없으면 2번
//	foo(10);// 3번 없으면 2번
//	const int c = 10;
//	foo(c); // 2번 없으면 error

	// 중요한 이야기
	int&& r = 10;
	foo(r);// 1
			// "이름있는 rvalue reference 는 lvalue 입니다."
			// rvalue 와 rvalue reference를 혼동하지 마세요
			// 10은 rvalue, r 은 rvalue reference(결국 lvalue)입니다.
			// 78 page 중간쯤.!!

	foo(static_cast<int&&>(r)); // 3
					// static_cast<int&&> : "rvalue" 로 캐스팅하는 코드입니다.
}






