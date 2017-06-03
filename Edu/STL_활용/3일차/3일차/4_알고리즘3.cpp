#include "show.h"

int main()
{
	int x[5] = { 1,2,3,4,5 };

	int* p1 = find(x, x + 5, 3);
	int* p2 = find_if(x, x + 5, [](int a) {return a % 2 == 0;});

	sort(x, x + 5); // < 연산으로 비교
	sort(x, x + 5, greater<int>()); // > 으로 비교
}