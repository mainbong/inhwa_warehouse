// 9_�Ϻ��������� - 106page
#include <iostream>
using namespace std;

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

// �ذ�å 1. �Լ� �����ε� Ȱ��
// ����. N �� ���ڸ� �Ϻ��ϰ� �����Ϸ��� 2^N ���� logTime�� �ʿ��ϴ�.!
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

	cout << n << endl; // 10���;� �Ѵ�.
}



