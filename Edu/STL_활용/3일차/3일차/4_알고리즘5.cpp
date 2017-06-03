#include "show.h"
#include <algorithm>
#include <numeric>// 범용수치 알고리즘

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 0};
	int z[5] = { 0 };

	//int n = accumulate(x, x + 5, 0); // 기본버전 + 사용
	//int n = accumulate(x, x + 5, 1, multiplies<int>());//연산자 지정버전 , 초기값은 1이여야 곱이 0이 안됨.
	int n = accumulate(x, x + 5, 0, 
		[](int a, int b) {return abs(a) + abs(b);});
	cout << n << endl;
	//--------------------------

	//partial_sum(x, x + 5, y);
	partial_sum(x, x + 5, y, multiplies<int>());

	for (int i = 0; i < 5; i++)
		cout << y[i] << " ";
}

// www.boost.org 에 접속해 보세요