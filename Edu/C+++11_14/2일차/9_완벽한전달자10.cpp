// �Ϻ��������� 1�� �����ؿ�����

#include <iostream>
using namespace std;

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

// �ذ�å 3. forward reference ���
template<typename F, typename T> void logTime(F f, T&& a)
{
	f(a);
}

int main()
{
	int n = 0;

	logTime(foo, 10); // T&& => int&&
	logTime(goo, n);  // T&& => int& 

	cout << n << endl; // 10���;� �Ѵ�.
}



