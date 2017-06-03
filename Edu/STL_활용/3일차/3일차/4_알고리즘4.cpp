#include "show.h"
#include <algorithm>
#include <numeric>// 범용수치 알고리즘

int main()
{
	int x[5] = { 1,2,3,4,5 };

	find(x, x + 5, 3);	//변경불가 시퀀스 알고리즘
	reverse(x, x + 5);	//변경가능 시퀀스 알고리즘
	sort(x, x + 5);		//정렬 관련 알고리즘

	int n = accumulate(x, x + 5, 0);	// 범용 수치 알고리즘.
	
	cout << n << endl;
}