#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// ���ٿ� �������� ĸ�� - 68 page
int main()
{
	int v1 = 10;
	int v2 = 20;

	//auto f1 = [](int a) { return a + v1; }; // error

	// Capture Local Variable
	//auto f1 = [v1](int a) { return a + v1; }; // ok
	//auto f1 = [v1, v2](int a) { return a + v1; }; // ok

	// ��� �������� ĸ��
	auto f1 = [=](int a) { return a + v1; }; // ok

	cout << f1(5) << endl;

	// �������� ĸ���� ����(=)
	class Closure_Object
	{
		int v1;
		int v2;
	public:
		Closure_Object(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			return v1 + a;
		}
	};
	Closure_Object(v1, v2); // �ᱹ ���������� ���� ��� ������ �����ϴ°�
}
