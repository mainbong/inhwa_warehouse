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

	// �Ǵ� ��ü�� �θ� Ÿ������ ĳ����
	cout << ((A)c).value << endl; // �� ĳ������  value�� �º��� �ü� �����ϴ�.
								// rvalue �ð�(����)����..
	cout << ((A&)c).value << endl; // ���� �ڼ���..

}