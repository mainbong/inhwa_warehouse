// 배열과 포인터
#include "show.h"

int main()
{
	int n = 10;			// n 은 int 타입
	double d = 3.4;		// d 는 double 타입

	int *p = &n;		// 주소를 꺼내려면 & 사용
						// 포인터 변수를 만들려면 변수 이름 앞에 * 표시.
	int x[5] = { 1,2,3,4,5 };

	int (*p2)[5] = &x; // 이 표현이 정확한 표현입니다. 배열의 주소.

	int *p3 = x;	// 배열의 주소 아닙니다.
					// 배열의 이름은 배열의 1번째 요소의 주소로 암시적 형변환 됩니다.
					// C++ 표준문서 4-2. Array to Pointer conversion 문법.

	printf("%p, %p\n", p2, p2 + 1); // 몇 바이트 차이 나는지 보세요.
	printf("%p, %p\n", p3, p3 + 1);

	int y[2][2] = { {1,1}, {2,2} };

	int(*p4)[2][2] = &y; // ok...
	int(*p5)[2] = y;
}