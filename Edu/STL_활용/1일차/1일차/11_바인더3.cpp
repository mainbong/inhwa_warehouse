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
//	void(*f1)(int) = &hoo; // C�� �Լ� ������!
//	f1 = &goo; // error

	// STL�� ������ �Լ� ������ ��ü
	function<void(int)> f = &hoo;
	f(10); // hoo(10);

	f = bind(&goo, _1, 7);
	f(10); // goo(10,7)

	f = bind(&foo, 2, 8, _1, 1);
	f(3); // 2, 8, 3, 1 ������ �غ�����...
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
	int(*f1)() = &foo; // ok.. ���� ��Ȯ�� ǥ���Դϴ�.
	int(*f2)() = foo; // ok.. ������, �Լ��� �ּҷ� �Ͻ��� ����ȯ�Ǿ ���Եǰ� �ֽ��ϴ�.

	void(Dialog::*f3)() = &Dialog::Close; // ok
	void(Dialog::*f4)() = Dialog::Close; // error. ����Լ� �̸���
										 // �Լ� �����ͷ� �Ͻ��� ����ȯ�� �ȵ˴ϴ�.
}