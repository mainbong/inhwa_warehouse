//10_begin_end - 19 page 항목2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// C++11의 개념 - 일반 함수 begin을 도입하자
/*
template<typename T> auto begin(T& c) { return c.begin(); }
template<typename T> auto end(T& c)   { return c.end(); }

// 배열버전의 일반 함수 begin()을 제공하자.
template<typename T, int N> T* begin(T(&arr)[N]) { return arr; }
template<typename T, int N> T* end  (T(&arr)[N]) { return arr+N; }
*/

// 알고리즘 함수 만들때 반복자를 꺼내는 2가지 방법
// 1. c.begin() : STL 컨테이너만 사용가능. 배열은 안된다
// 2. begin(c)  : STL 컨테이너 + 배열, 모두 사용가능

// 멤버 함수 보다는 일반함수 begin()을 사용하자!!


template<typename T> void show(T& c)
{
	//auto p = c.begin();
	auto p = begin(c);

	while (p != end(c) )
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);
	show(x);
}