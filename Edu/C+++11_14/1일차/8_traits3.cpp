// traits1번 복사해오세요
#include <iostream>
using namespace std;

template<typename T> struct IsPointer      { enum { value = false };};
template<typename T> struct IsPointer<T*>  { enum { value = true };};

template<typename T> void printv(T v)
{
	// C++ 컴파일러의 원리
	// 1. 사용된 함수의 T의 타입이 결정되면 실제 함수 생성 => T는 int !!
	// 2. 생성된 함수 컴파일
	// 3. 실행되지 않은 부분 최적화해서 제거.
	if ( IsPointer<T>::value )		// if ( false ) 로 코드 생성
		cout << v << ", " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int    n = 3;
	printv(n); // 1. error 발생.
	//printv(&n);// 2
}
// 빌드하면 에러가 있습니다. 왜 에러인지 생각해보세요 . 1,2중에러의 원인은 ?




