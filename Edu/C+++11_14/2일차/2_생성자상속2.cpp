#include <iostream>
using namespace std;

class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int a) : value(a) {}
};
class Derived : public Base
{
public:
	// C++11 �� �����ڵ� using ��Ӱ����մϴ�.
	using Base::Base; // �θ� �����ڸ� ����� �޶�!!

	Derived() {}
};
int main()
{
	Derived d1;
	Derived d2(1); //?
}



