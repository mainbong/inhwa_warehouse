#include <iostream>
using namespace std;

int x = 10;

int& foo(int a) { return x; }

/*
// f()가 참조를 리턴하면 문제가 된다.
template<typename F, typename T> auto logTime(F f, T a)
{
	return f(a);
}
*/

// f()가 참조리턴일 경우를 고려해서 아래처럼 해야 합니다.
// C++14
/*
template<typename F, typename T>
decltype(auto) logTime(F f, T a)
{
	return f(a);
}
*/
// C++14를 사용할수 없는 환경이라면 아래 처럼 하면 C++11도 됩니다.
// f()가 참조리턴을 해도 정확히 전달됩니다.
template<typename F, typename T>
auto logTime(F f, T a) -> decltype(f(a))
{
	return f(a);
}

// g++ 소스이름.cpp --std=c++11      C++11문법으로
// g++ 소스이름.cpp --std=c++1y      C++14문법으로

int main()
{
	int& k = logTime(foo, 10);

	k = 20;

	cout << x << endl; 
	
}





