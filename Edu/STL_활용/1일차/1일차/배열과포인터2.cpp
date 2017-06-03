#include "show.h"

// void foo(int x[5]);
int main()
{
	int n1 = 10;
	int n2 = n1;
	int& r = n1;

	int x[5] = { 1,2,3,4,5 };
	int y[5] = x;	// error. 배열과 함수는 자신의 타입으로 초기화 될 수 없다.
					// 대신, 1번째 요소의 주소로 형변환 될 수 있다.
//  foo(x);
	int *p = x; // ok
	
	int(&r2)[5] = x; // ok , memory overhead 가 없으니까 허용.
}