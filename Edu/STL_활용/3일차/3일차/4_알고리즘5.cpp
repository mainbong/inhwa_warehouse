#include "show.h"
#include <algorithm>
#include <numeric>// �����ġ �˰���

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 0};
	int z[5] = { 0 };

	//int n = accumulate(x, x + 5, 0); // �⺻���� + ���
	//int n = accumulate(x, x + 5, 1, multiplies<int>());//������ �������� , �ʱⰪ�� 1�̿��� ���� 0�� �ȵ�.
	int n = accumulate(x, x + 5, 0, 
		[](int a, int b) {return abs(a) + abs(b);});
	cout << n << endl;
	//--------------------------

	//partial_sum(x, x + 5, y);
	partial_sum(x, x + 5, y, multiplies<int>());

	for (int i = 0; i < 5; i++)
		cout << y[i] << " ";
}

// www.boost.org �� ������ ������