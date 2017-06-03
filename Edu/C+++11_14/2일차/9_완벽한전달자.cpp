// 9_�Ϻ�������� - 106page
#include <iostream>
using namespace std;

// perfect forwarding : ���� �Լ�(Ŭ����)�� ���鶧 ���ڸ� �Ϻ��ϰ� ����ϴ±��

void foo(int a)  { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

template<typename F, typename T> void logTime(F f, const T& a)
{
	f(a);
}
int main()
{
	int n = 0;
//	foo(10);
//	goo(n);

	logTime(foo, 10);
	logTime(goo, n);

	cout << n << endl; // 10���;� �Ѵ�.
}


