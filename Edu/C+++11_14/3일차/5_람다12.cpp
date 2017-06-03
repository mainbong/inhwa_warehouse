#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// ���ٿ� �������� ĸ�� - 68 page
int main()
{
	int v1 = 10;
	int v2 = 20;
	//auto f1 = [=](int a) { v1 = 0;  return a + v1; }; // error
	// mutable ����!!. ���������� ĸ���� ��� ������ mutable�̴�
	auto f1 = [=](int a) mutable { v1 = 0;  return a + v1; };
							// v1 = 0�� ����(��������)�� �ƴ� ���纻�� 
							// ����Ǵ� ���Դϴ�.
	f1(5);
	cout << v1 << endl;// 10 

/*
	// �������� ĸ���� ����(=)
	class Closure_Object
	{
		mutable int v1;
		mutable int v2;
	public:
		Closure_Object(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 0;
			return v1 + a;
		}
	};
	Closure_Object(v1, v2); // �ᱹ ���������� ���� ��� ������ �����ϴ°�
*/
}

// www.cppreference.com



