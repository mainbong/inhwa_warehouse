// 2_�����ڻ�� - 57 page
#include <iostream>
using namespace std;

class Base
{
public:
	void foo(int a)        { cout << "int" << endl; }
	void foo(int a, int b) { cout << "int, int" << endl; }
};
class Derived : public Base
{
public:
	// �ڽĿ��� foo�� ����� �θ� �ִ� ��� foo�Լ��� ��������(hide)�ȴ�.
	// ��, �θ� �ڽİ��� �Լ������� �����ε��� ���� �ʴ´�.

	// �θ��� foo�� ��� �ް� �ʹٸ� - C++98/03����
	using Base::foo;

	void foo(double a) { cout << "double" << endl; }
};

int main()
{
	Derived d;
	// ������ ������ ��� ������, ������ ���� �ʴ°��� ����� �����غ�����..
	d.foo(1);	// double
	d.foo(1, 2);// error
	d.foo(3.4); // double
}



