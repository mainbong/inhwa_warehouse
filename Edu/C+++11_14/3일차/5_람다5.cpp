#include <iostream>
using namespace std;

struct Plus
{
	// ��κ� �Լ���ü�� () ������ �Լ��� ��� �Լ��� ����� ����
	// �����ϴ�. �Ʒ� foo()�� ������ ������!!
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

template<typename T> void foo(const T& a)
{
	// a�� ��� ��ü�� �ȴ�.
	// ��� ��ü�� ��� �Լ��� ȣ���Ҽ� �ִ� - C++ �⺻ ����å ����
	int n = a(1, 2);
}


int main()
{
	Plus p;
	
	foo(p);
}




