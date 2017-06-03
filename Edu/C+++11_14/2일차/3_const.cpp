// 3_const - 60 page
#include <iostream>
using namespace std;

// C++98/03 ���� const�� ������
int main()
{
	//const int c = 10; // compile time constant
						// ������ c�� ������ ��ũ�� ó�� 10���� ������ �ð���
						// ġȯ�ȴ�.
	int n = 10;
	cin >> n;
	const int c = n; // Run time constant
					 // ������ �ð����� ���� �˼� ����.


	//int* p = &c; // error. ���� �����Ϳ� ����� �ּҸ� ������ ����.

	int* p = (int*)&c; // �Ǵ� const_cast<int*>(&c);
						// ����� ��ȯ�� ���ȴ�.
	*p = 20;

	cout << c  << endl; // 10
	cout << *p << endl; // 20
}







