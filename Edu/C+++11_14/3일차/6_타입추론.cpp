// 6_타입추론 - 92 ~ 
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T> class TD; // 선언만 한다.


template<typename T> void foo(T a)
{
	// T의 타입을 알고 싶다면 - 정확하지 않다!!
//	cout << typeid(T).name() << endl;

//	TD<T> a; //  선언만 있으므로 에러 발생. 에러메세지를 보면 T를 알수 있다

	// boost의 type_index 라이브러리 사용 - 비교적 정확하지만.. 완전하지는 않다.
	// 교재 90page 예제 참고
}


int main()
{
	int n = 0;
	const int& r = n;

	foo(n); // T 는 int

	foo(r); // T ? int ? int& ? const int& ? const int
}






