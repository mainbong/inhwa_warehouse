// 8_유틸리티3
#include "show.h"
/*
template<typename T, typename U> struct pair
{
	T first;
	U second;
};
*/
pair<int,double> foo(pair<int,double> p)
{
	return p;
}

int main()
{
	//pair<int, double> p(1, 3.4);
	//foo(p);
	//foo(pair<int,double>(1, 3.4));// 임시객체 사용

	foo(make_pair(1, 3.4)); // 함수 템플릿으로 클래스템플릿 객체(pair)생성

	pair<int, pair<int, int>> p3;
	pair<int, pair<int, pair<int, int>>> p4;
	// 복잡제. 복잡해서 튜플이 생긴기라.
}