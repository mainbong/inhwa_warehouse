// 11_바인더
#include "show.h"

int main()
{
	modulus<int> m; // %연산, 이항 함수 객체
	int n = m(10, 3); // 10 % 3
	cout << n << endl; // 1

	// 이항 함수객체를 단항함수객체로 변경하는 도구
	binder2nd<modulus<int>> f(m, 3); // m의 2번째 인자를 3으로 고정한 단항함수 f
	
	cout << f(10) << endl; // m(10,3) => 10 % 3

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 3의 배수를 찾고 싶다.
	//int* p = find_if(x, x + 10, m); // 될까요 ? error.
									// find_if()의 3번째 인자는 단항함수이어야 한다.

	//int* p = find_if(x, x + 10, f); // ok. 단, 3의 배수가 아닌 것 찾기.

	// binder2nd<>를 만들어주는 헬퍼함수 사용

	int* p = find_if(x, x + 10, bind2nd(m, 3));

	cout << *p << endl;
}