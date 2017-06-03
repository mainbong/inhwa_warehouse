// 2_단위전략
#include "show.h"
#include <set> // STL의 set, RB tree 입니다.

/*
template<typename T, typename Pred = less<T>> class set
{
	Pred pred; // 비교 정책을 담은 함수 객체.
public:
	// 그냥 비교하면 확장성이 떨어진다.
	// 함수 포인터로 비교함수를 받으면 inline 치환이 안되서 성능저하가 심하다
	// 따라서 STL 은 템플릿을 사용함
	void insert(const T& a)
	{
		//if (기존요소 > a)
		if ( pred(기존요소, a))
			왼쪽에 넣기;
		else
			오른쪽에 넣기;
	}
}
*/
int main()
{
	set<int, greater<int>> s; // greater : > 연산

	s.insert(10);
	s.insert(15);
	s.insert(20);
	s.insert(13);
	s.insert(31);
	s.insert(31);
	// set 반복자를 ++ 하면 inorder 방식(정렬유지)로 순회
	show(s);
}