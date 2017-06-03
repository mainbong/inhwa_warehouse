#include <iostream>
using namespace std;

// ���۷����� �Լ� �����ε� ��Ģ
void foo(int& a)       { cout << "int&" << endl; }		// 1
void foo(const int& a) { cout << "const int&" << endl; }// 2
void foo(int&& a)	   { cout << "int&&" << endl; }		// 3

int main()
{
	int n = 10;
//	foo(n); // 1�� ������ 2��
//	foo(10);// 3�� ������ 2��
//	const int c = 10;
//	foo(c); // 2�� ������ error

	// �߿��� �̾߱�
	int&& r = 10;
	foo(r);// 1
			// "�̸��ִ� rvalue reference �� lvalue �Դϴ�."
			// rvalue �� rvalue reference�� ȥ������ ������
			// 10�� rvalue, r �� rvalue reference(�ᱹ lvalue)�Դϴ�.
			// 78 page �߰���.!!

	foo(static_cast<int&&>(r)); // 3
					// static_cast<int&&> : "rvalue" �� ĳ�����ϴ� �ڵ��Դϴ�.
}






