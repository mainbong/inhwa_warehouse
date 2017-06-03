#include <iostream>
using namespace std;

// auto와 함수리턴!!
/*
template<typename T, typename U> 
decltype(a*b) Mul(T a, U b)  // a,b가 선언되기 전에 사용되고 있다. error
{
	return a * b;
}
*/
/*
// C++11에서 ok..
template<typename T, typename U>
auto Mul(T a, U b) -> decltype(a*b)
{
	return a * b;
}
*/
// 리턴문으로 auto 를 추론할수 도 있다.
// 단점. auto 리턴 으로 하면 참조를 무시하게 된다.
/*
template<typename T, typename U>
auto Mul(T a, U b) 
{
	return a * b;
}
*/
// c++14 부터 아래 처럼 합니다.
template<typename T, typename U>
decltype(auto) Mul(T a, U b)
{
	return a * b;
}



int main()
{
	cout << Mul(3.4, 2) << endl;
}






