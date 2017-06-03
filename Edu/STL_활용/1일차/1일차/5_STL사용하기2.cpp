// 5_STL 사용하기
/*
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm> // find() 같은 함수가 이 헤더에 있습니다.
using namespace std; // 흔히 "알고리즘" 이라고 합니다.

// 모든 컨테이너의 요소를 출력하는 함수
template<typename T> void show(T& c)
{
	typename T::iterator p = c.begin();
	while (p != c.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/
#include "show.h"

int main()
{	
	typedef list<int> Cont;

	Cont s1 = { 1,2,3,4,5,6,7,8,9,10 };
	show(s1);
}