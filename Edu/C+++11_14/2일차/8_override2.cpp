#include <iostream>
using namespace std;

template<typename T> class Base
{
public:
	// T�� ������ ǥ��
	// T �� int* �� ������ �ᱹ �����Ͱ� �����°�.
	//virtual void foo(const T& p) { cout << "Base foo" << endl; }
	 
	virtual void foo( T const& p) { cout << "Base foo" << endl; }
};

class Derived : public Base<int*>
{
public:
	// �Ʒ� ǥ���� ����� ����Ű�� �������� ����
	//virtual void foo(const int*& p) override { cout << "Derived foo" << endl; }

	//�Ʒ��� �´� ������ ǥ���Դϴ�.
	virtual void foo(int* const& p) override { cout << "Derived foo" << endl; }
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // �ڽ� �Լ��� ȣ��Ǿ� �մϴ�
}





