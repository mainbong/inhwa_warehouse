#include <iostream>
using namespace std;


struct Point { int x, y; };

Point p = { 1, 2 };

Point  foo() { return p; }
Point& goo() { return p; }

// 76 page �� �����Ǿ� �ֽ��ϴ�. - ���� "rvalue vs lvalue"�� ������ �ּ���
// rvalue : =�� �����ʿ��� ����.       �̸��� ����. ���������� ����
//			���� �����ϴ� �Լ�
// lvalue : =�� ����, ������ ��� ����.�̸��� �ִ�. �����Ⱓ �޸𸮿� ����
//			������ �����ϴ� �Լ�

int main()
{
	int n1 = 0;
	int n2 = 0;
	10 = n1; // error. 10�� =�� �����ʸ� �����ϴ�. rvalue 
	n1 = 10; // ok. n1 �� lvalue
	n2 = n1; //

	foo().x = 10; // error
	goo().x = 10; // ok
}





