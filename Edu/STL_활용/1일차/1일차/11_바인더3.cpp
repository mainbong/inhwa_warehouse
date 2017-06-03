#include "show.h"

using namespace std::placeholders; // _1, _2, _3...
/*
void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

void goo(int a, int b)	{ cout << "goo" << endl; }
void hoo(int a)			{ cout << "hoo" << endl; }

int main()
{
//	void(*f1)(int) = &hoo; // C의 함수 포인터!
//	f1 = &goo; // error

	// STL의 범용적 함수 포인터 객체
	function<void(int)> f = &hoo;
	f(10); // hoo(10);

	f = bind(&goo, _1, 7);
	f(10); // goo(10,7)

	f = bind(&foo, 2, 8, _1, 1);
	f(3); // 2, 8, 3, 1 나오게 해보세요...
}
*/

class Dialog
{
	void 
}

void foo() {}

int main()
{
	int a;
	int(*f1)() = &foo; // ok.. 아주 정확한 표현입니다.
	int(*f2)() = foo; // ok.. 하지만, 함수가 주소로 암시적 형변환되어서 대입되고 있습니다.

	void(Dialog::*f3)() = &Dialog::Close; // ok
	void(Dialog::*f4)() = Dialog::Close; // error. 멤버함수 이름은
										 // 함수 포인터로 암시적 형변환이 안됩니다.
}