// 7_��Ʈ���ݺ���
#include "show.h"

// 1. copy �˰���
int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	vector<int> v(10, 0);

	copy(x, x + 10, v.begin()); // x => v�� ����

	show(v);
}