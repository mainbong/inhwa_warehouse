// 11_���δ�
#include "show.h"

int main()
{
	modulus<int> m; // %����, ���� �Լ� ��ü
	int n = m(10, 3); // 10 % 3
	cout << n << endl; // 1

	// ���� �Լ���ü�� �����Լ���ü�� �����ϴ� ����
	binder2nd<modulus<int>> f(m, 3); // m�� 2��° ���ڸ� 3���� ������ �����Լ� f
	
	cout << f(10) << endl; // m(10,3) => 10 % 3

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 3�� ����� ã�� �ʹ�.
	//int* p = find_if(x, x + 10, m); // �ɱ�� ? error.
									// find_if()�� 3��° ���ڴ� �����Լ��̾�� �Ѵ�.

	//int* p = find_if(x, x + 10, f); // ok. ��, 3�� ����� �ƴ� �� ã��.

	// binder2nd<>�� ������ִ� �����Լ� ���

	int* p = find_if(x, x + 10, bind2nd(m, 3));

	cout << *p << endl;
}