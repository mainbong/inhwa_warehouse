// 2_STL�˰���1.cpp - ���� 2 page
#include <iostream>
using namespace std;

// 5�ܰ�. �˻� ���н� ... ��Ʈ�� �����ϰ� �ٲ㺸��

// �˻� ���� : [first, last) ������ ��� Ÿ���� �迭�� �κ� ����
// ���� �̵� : ������ ++
// ������ ǥ�� : �ݵ�� �������� �ʿ�� ����.
// ������ ���� : last

// last�� "past the end" ��� �մϴ�.
template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first;// == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 15);

	if (p == x + 10)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}