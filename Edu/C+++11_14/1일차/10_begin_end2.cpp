//10_begin_end - 19 page 항목2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// 컨테이너 버전.
template<typename T> void showImp(T& c, false_type) // 배열이 아닐때
{
	auto p = c.begin();
	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}
// 배열 버전
template<typename T> void showImp(T& c, true_type) 
{
	auto p = c; // 배열은 이름이 주소이다

	while (p != c + extent<T, 0>::value ) // extent<T, 0>::value  T배열의0번째크기
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

template<typename T> void show(T& c)
{
	// 배열인지를 조사해서 함수 오버로딩 사용
	showImp(c, is_array<T>() );
}


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);
	show(x);
}