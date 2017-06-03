// 2_STL알고리즘1.cpp - 교재 2 page
#include <iostream>
using namespace std;

// 5단계. 검색 실패시 ... 라스트를 리턴하게 바꿔보자

// 검색 구간 : [first, last) 사이의 모든 타입의 배열의 부분 구간
// 구간 이동 : 전위형 ++
// 구간의 표현 : 반드시 포인터일 필요는 없다.
// 실패의 전달 : last

// last를 "past the end" 라고 합니다.
template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first;// == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 15);

	if (p == x + 10)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}