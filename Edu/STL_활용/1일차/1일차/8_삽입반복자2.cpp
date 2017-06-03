#include "show.h"

int main()
{
	list<int> s(5, 0);

	int x[5] = { 1,2,3,4,5 };

	// 덮어쓰기
	// copy(x, x + 5, s.begin());

	// 끝에 추가하기
	// copy(x, x+5, back_inserter(s));

	// 앞에 추가해 보세요.
	//copy(x, x + 5, front_inserter(s)); // front_insert_iterator<> 를 생성


	// 중간에 넣기 : s 의 2번째 넣기
	//copy(x, x + 5, inserter(s, ++s.begin()));


	// 임의 삽입을 통한 앞에 넣기
	copy(x, x + 5, inserter(s, s.begin())); // 1 2 3 4 5 0 0 0 0 0
												// 클래스 버전 : insert_iterator<T>
	show(s);
}