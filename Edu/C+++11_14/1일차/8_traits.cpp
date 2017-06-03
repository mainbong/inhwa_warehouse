// 8_traits - 8 page
#include <iostream>
using namespace std;

// Traits : T�� �پ��� �Ӽ�(Ư��)�� �����ϴ� ���
//			2000�� �ʹݿ� ���ͼ� C++11���� ���� ǥ������ ä�õ�.!
template<typename T> void printv(T v)
{
	if (T is Pointer)
		cout << v << ", " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	double d = 3.4;
	int    n = 3;
	printv(d);
	printv(n);
	printv(&n);
}





