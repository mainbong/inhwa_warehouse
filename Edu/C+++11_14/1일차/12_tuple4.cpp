#include <iostream>
using namespace std;

class A
{
public:
	int value;
	A() : value(10) {}
};
class B : public A
{
public:
	int value;
	B() : value(20) {}
};

class C : public B {};

int main()
{
	C c;
	cout << c.value << endl; // 20
	cout << c.B::value << endl; // 20
	cout << c.A::value << endl; // 10

	// 또는 객체를 부모 타입으로 캐스팅
	cout << ((A)c).value << endl; // 값 캐스팅은  value가 좌변에 올수 없습니다.
								// rvalue 시간(내일)설명..
	cout << ((A&)c).value << endl; // 내일 자세히..

}