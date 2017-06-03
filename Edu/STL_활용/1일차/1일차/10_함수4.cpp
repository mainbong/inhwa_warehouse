// 10_�Լ�3
#include "show.h"

int foo(int a, int b)
{
	cout << "foo" << endl;
	return a + b;
}

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 1,2,-3,4,5 };

	vector<int> v(5, 0);

	// 1. �Ϲ� �Լ�	
	// transform(x, x + 5,y, v.begin(), foo);

	// 2. �Լ� ��ü.
	// plus<int> p;
	// transform(x, x + 5, y, v.begin(), p);

	// transform(x, x + 5, y, v.begin(), plus<int>()); // Ŭ�����̸�() : �ӽð�ü����, ������ ������ �ı�

	// 3. C++11 �� ���� ǥ���� ����
	transform(x, x + 5, y, v.begin(), [](int a, int b) {return a + b;});

	show(v);
}