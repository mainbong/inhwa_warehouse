// 5_STL 사용하기
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm> // find() 같은 함수가 이 헤더에 있습니다.
using namespace std; // 흔히 "알고리즘" 이라고 합니다.

int main()
{
	string s = "hello world";

	string::iterator p1 = s.begin();
	++p1;
	cout << *p1 << endl; // 'e'

	typedef list<int> Cont;

	Cont s1 = { 1,2,3,4,5,6,7,8,9,10 }; // C++11 최신 문법.

	// s1 반복자 꺼내서 전부 출력해 보세요
	Cont::iterator s1_iter = s1.begin();
	while (s1_iter != s1.end())
	{
		cout << *s1_iter << endl;
		++s1_iter;
	}
	

	// s1 뒤집어 보세요. 뒤집는 알고리즘은 reverse() 입니다.
	//s1.reverse();
	reverse(s1.begin(), s1.end());
	
	// s1 다시 출력해보세요..
	s1_iter = s1.begin();
	while (s1_iter != s1.end())
	{
		cout << *s1_iter << endl;
		++s1_iter;
	}
}
