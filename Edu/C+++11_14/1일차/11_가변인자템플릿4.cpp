#include <iostream>
using namespace std;

void foo(int a)        { cout << "foo" << endl; }
void goo(int a, int b) { cout << "goo" << endl; }
void hoo()				{ cout << "hoo" << endl; }

// �Լ��� ���� ������ ���� logTime()�� �ٽ� ������ ���ô�.

// �Ϻ��� ������(perfect forwarding) : �Լ��� ���ڸ� �޾Ƽ� �ٸ� �Լ��� �����ϴ�
//								���۸� ���鶧, ���ڸ� ��� �Ϻ��ϰ� �����ϰ�
//								����� ���(�׸� 2-19���� �ڼ��� �Ұ�)
template<typename F, typename ... Types> 
void logTime(F f, Types ... args)
{
	f(args...); // ... �� ����
}

int main()
{
	logTime(foo, 10);
	logTime(goo, 10, 20);
	logTime(hoo);
}







