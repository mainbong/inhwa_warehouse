#include <iostream>
using namespace std;

// ref()��뿹��
void foo()       { cout << "foo" << endl; }
void goo(int& a) { a = 10; }

// C++11ǥ���� �����ϴ� ������ �Լ������� ��Ȱ�� ��ü
#include <functional>

int main()
{
	function<void()> f = &foo;
	f(); // foo ȣ��!!

	int n = 0;

	f = bind(&goo, ref(n) ); // goo�� ���ڸ� n���� ����
	f(); // goo(n)

	cout << n << endl; // 10 ���;� �մϴ�!
}






/*
int main()
{
	void(*f1)() = &foo; 

	f1 = &goo; // ?
}
*/