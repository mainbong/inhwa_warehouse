#include "show.h"

using namespace std::placeholders; // _1, _2, _3...

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

// �� �ҽ��� ���δ��� �ٽ��Դϴ�.
int main()
{
	modulus<int> m;

	cout << m(10, 3) << endl;

	// bind1st(), bind2nd() : �����Լ� ��ü�� ���� �Լ���ü��..
	//							C++11���� deprecated
	cout << bind2nd(m, 3)(10) << endl; // 10 % 3
	cout << bind1st(m, 3)(2) << endl; // 3 % 2

	// C++11 bind() : �Լ���ü �� �ƴ϶�.. �Ϲ� �Լ���
	//					M ���� N ������
	cout << bind(m, _1, 5)(10) << endl; // m(10, 5) 10 % 5

	cout << bind(m, 10, _1)(3) << endl; // 10 % 3

	cout << bind(m, 10, 3)() << endl; // 10 % 3

	bind(&foo, 3, _2, 2, _1)(9, 7);
}
