// 10_함수
#include "show.h"

// 알고리즘에 인자로 함수가 전달되는 경우가 많습니다.
// 단항 함수 : 인자가 한개인 것
// 이항 함수 : 인자가 2개인 것


bool foo(int a) { return a % 4 == 0; }

int main()
{
	list<int> s = { 1,2,3,8,7,6 };

	// 1. s 에서 처음 나오는 3을 찾아보세요.
	list<int>::iterator p1 = find(s.begin(), s.end(), 3); // 상수 검색
	cout << *p1 << endl; // 3
	
	// 2. s 에서 처음 나오는 4의 배수를 찾아보세요.
	list<int>::iterator p2 = find_if(s.begin(), s.end(), foo); // 조건 검색
	cout << *p2 << endl; // 8
}