#include <iostream>
using namespace std;

// 17 page - �߿��� ���� �Դϴ�.
int  foo(int* p, int n)
{
	for (int i = 0; i < 10000; i++)
		cout << "*";
	cout << endl;
	return 10;
}

#include "logTime.h" // ī�信�� �ٿ� �������� 
					 // cafe.naver.com/cppmaster
					 // ���� ������Ʈ ������ ������ �μ���..
int main()
{
	// ���� ! ������ 0 ��� nullptr ����ؾ� �մϴ�.
	int n = logTime(foo, nullptr, 10); 
}





