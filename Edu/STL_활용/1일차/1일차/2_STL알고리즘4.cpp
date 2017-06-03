// 2_STL알고리즘1.cpp - 교재 2 page
#include <iostream>
using namespace std;

// 4단계. 보다 generic 하게..!!

// 아래처럼 하면 2개의 문제점이 있습니다.

// 1. 구간의 타입과 요소의 타입이 연관됩니다. double배열에서 int를 찾을 수 없습니다.
// 2. T* 라고 하면 진짜 포인터만 사용해야 합니다. 
//		스마트 포인터를 사용할 수 없습니다.

//template<typename T> T* xfind(T* first, T* last, T value)

// 해결책
template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 5);

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}