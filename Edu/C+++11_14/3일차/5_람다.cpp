// 5_���� - 64page ~
#include <iostream>
using namespace std;

// �Լ���ü ����
// () �����ڸ� ������ �ؼ� �Լ� ó�� ��밡���� ��ü(Function Object, Functor)
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(1, 2); // p.operator()(1,2)
	cout <<  n << endl; // 3
}




