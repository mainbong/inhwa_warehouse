//10_�Լ�2
#include "show.h"

// �Լ����� �Լ� ��ü�� ����.
// �Լ� ��ü : () �����ڸ� �������ؼ� �Լ�ó�� ��밡���� ��ü
// ���� : 1. ��ü�̹Ƿ� ���¸� ���� �� �ִ�. �Ϲ� �Լ��� ���°� ����.
//			���¿� �����ڸ� �� Ȱ���ϸ� ���뼺�� ��������.

//		  2. �ζ��� ġȯ�ȴ�.

find_if(s.begin(), s.end(), foo); // foo �Լ��� �ٽ� ȣ��� �� ġȯ �ȵ�

Modulus m(4);
find_if(s.begin(), s.end(), m); // m �Լ���ü�� �ٽ� ȣ��� �� ġȯ��

struct Modulus
{
	int value;
	Modulus(int n) : value(n) {}
	int operator() (int a)
	{
		return a % value == 0;
	}
};

int main()
{
	Modulus m(3);
	bool b = m(4); // m.operator()(4)
	cout << b << endl;

	// a + b; // a.operator+(b)
	// a - b; // a.operator-(b)
	// a();   // a.operator()()
	// a(1);  // a.operator()(1)
}