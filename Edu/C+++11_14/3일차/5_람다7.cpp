#include <iostream>
#include <typeinfo>
using namespace std;

//���ٿ� Ÿ�� - 65page 3��
// ��� ���ٴ� �ٸ� Ÿ���̴�(�Լ���ü�̹Ƿ�)
int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	// RTTI�� ����ϸ� Ư�� ������ Ÿ���̸��� ����Ҽ� �ֽ��ϴ�.
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
}


