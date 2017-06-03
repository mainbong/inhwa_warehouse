// 1_typedef2
#include "show.h"

// 주어진 구간의 합을 구하는 함수
/*
int sum(int* first, int* last)
{
	int s = 0;
	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
}
*/

// 반복자의 종류
// 1. 진짜 포인터
// 2. 객체형 반복자..
// 위 2개의 차이점 때문에 일반화 함수를 만들기 어렵습니다.
// 해결책
/*
template<typename T> struct iterator_traits
{
	typedef typename T::value_type value_type;
};

// 포인터는 이리로 오도록 !! 와우! 마법의 템플릿
template<typename T> struct iterator_traits<T*>
{
	typedef T value_type;
};
*/
// 반복자도 자신이 가르키는 타입이 있습니다. T::value_type

template<typename T> typename iterator_traits<T>::value_type sum(T first, T last)
{
	// 근데 요렇게 만드니까 x[10]을 위한 sum 이 안되네.
	//typename T::value_type s = 0;
	// 포인터까지 받아올수 있는 벨류타입을 위하여!

	typename iterator_traits<T>::value_type s = 0;
	// auto 를 써서 아래와 같이 받을수도!
//	auto s = *first;
//	first++;

	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
};

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sum(x, x + 10) << endl;

	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sum(v.begin(), v.end()) << endl;
}