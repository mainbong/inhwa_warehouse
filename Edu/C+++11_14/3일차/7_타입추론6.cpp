// Ÿ���߷�6. auto�� Ÿ�� �߷� - 98 page
#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

// auto : template �߷а� ������ ��Ģ ��� - 98 page
// T    param     foo( expr )
// auto param =        r;

int main()
{
	auto n1 = foo(); // n1�� int
	n1 = 20; // x�� ������ �ʴ´�.

	decltype(foo()) n2 = foo(); // n2�� int&

	// C++14���� ���Ӱ� ���� �ڵ�
	decltype(auto) n3 = foo(); // �캯����Ÿ���� �����ϴµ�
								// �߷� ��Ģ�� decltype ��Ģ����!

	// decltype���� ��������.
	int n4 = 10;
	int* p = &n4;
	decltype(*p) n5 = n4; // ���� Ÿ���ϱ�� int&
}




/*
int main()
{
	int  n = 10;
	int& r = n;

	auto  a = r; // a�� int 
	auto& a1 = r; // a1�� int&

	decltype(r) d2 = r; // int&

	a = 20;
	cout << r << endl; // 10 ? 20
}
*/





