// 9_�Ϻ��������� - 106page
#include <iostream>
using namespace std;

// perfect forwarding : ���� �Լ�(Ŭ����)�� ���鶧 ���ڸ� �Ϻ��ϰ� �����ϴ±��

int foo(int a) { cout << "foo" << endl; return 100; }
void goo(int& a) { cout << "goo" << endl; a = 10; }
// webkit/webkit/Source/WTF/WTF/NeverDestroyed.h ���� ������


// �Ϻ��� �����ڰ� �Ƿ���
// 1. ���ڸ� Universal(forward) reference ���
// 2. ���� �Լ��� ������ ���ڸ� �ٽ� _forward_ �� ��� ����
// 3. forward<T&&> ����� ����� �߷л��
// 4. �������� ���ø�����!!
template<typename F, typename ... Types> 
auto logTime(F f, Types&& ... args) 
{
	//f(forward<Types&&>(args...)); // error
	//return f(forward<Types&&>(args)...); // ok..
	return f(forward<Types>(args)...); // ok..
}


int main()
{
	int n = 0;
	int x = logTime(foo, 10);

	cout << x << endl;
	logTime(goo, n);

	cout << n << endl;
}



