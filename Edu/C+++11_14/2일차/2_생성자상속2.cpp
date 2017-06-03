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
	// C++11 은 생성자도 using 상속가능합니다.
	using Base::Base; // 부모 생성자를 상속해 달라!!

	Derived() {}
};
int main()
{
	Derived d1;
	Derived d2(1); //?
}



