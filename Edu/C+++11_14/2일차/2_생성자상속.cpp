// 2_생성자상속 - 57 page
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
	// 자식에서 foo를 만들면 부모에 있는 모든 foo함수는 가려지게(hide)된다.
	// 즉, 부모 자식간의 함수에서는 오버로딩이 되지 않는다.

	// 부모의 foo를 상속 받고 싶다면 - C++98/03문법
	using Base::foo;

	void foo(double a) { cout << "double" << endl; }
};

int main()
{
	Derived d;
	// 다음중 에러를 모두 고르세요, 에러가 나지 않는것의 결과도 예측해보세요..
	d.foo(1);	// double
	d.foo(1, 2);// error
	d.foo(3.4); // double
}



