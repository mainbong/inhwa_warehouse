#include "show.h"

// void foo(int x[5]);
int main()
{
	int n1 = 10;
	int n2 = n1;
	int& r = n1;

	int x[5] = { 1,2,3,4,5 };
	int y[5] = x;	// error. �迭�� �Լ��� �ڽ��� Ÿ������ �ʱ�ȭ �� �� ����.
					// ���, 1��° ����� �ּҷ� ����ȯ �� �� �ִ�.
//  foo(x);
	int *p = x; // ok
	
	int(&r2)[5] = x; // ok , memory overhead �� �����ϱ� ���.
}