#include "show.h"
#include <algorithm>
#include <numeric>// �����ġ �˰���

int main()
{
	int x[5] = { 1,2,3,4,5 };

	find(x, x + 5, 3);	//����Ұ� ������ �˰���
	reverse(x, x + 5);	//���氡�� ������ �˰���
	sort(x, x + 5);		//���� ���� �˰���

	int n = accumulate(x, x + 5, 0);	// ���� ��ġ �˰���.
	
	cout << n << endl;
}