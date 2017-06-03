// 8_traits2
#include <iostream>
using namespace std;

// T가 포인터 인지 조사하는 기술

// traits 기술을 만드는 핵심 
// primary template : false 리턴(value = false)라는 의미
// 부분 전문화 버전 : true 리턴(value = true)라는 의미

// 컴파일 시간에 T에 대해 조사해서 알고리즘을 선택하게 하는 일종의 메타 함수!!

template<typename T> struct IsPointer
{
	enum { value = false };
};
template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};
template<typename T> void foo(const T& a)
{
	if ( IsPointer<T>::value ) // 구조체이름::enum상수
		cout << "포인터 입니다" << endl;
	else
		cout << "포인터가 아닙니다." << endl;
}
int main()
{
	int n = 10;
	foo(n);

	foo(&n);
}
