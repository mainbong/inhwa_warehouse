// 9_완벽한전달자 - 106page
#include <iostream>
using namespace std;

template<typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}
	operator T&() { return *obj; }
};

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

// 클래스 템플릿은 T의 암시적 추론이 불가능해서 항상 어렵습니다.
// 암시적 추론이 가능한 함수 템플릿을 헬퍼로 도입합니다.
template<typename T> 
xreference_wrapper<T> xref(T& a)
{
	return xreference_wrapper<T>(a);
}



int main()
{
	int n = 0;

//	xreference_wrapper<int> r(n);
//	logTime(goo, r);
	//logTime(goo, xreference_wrapper<int>(n)); // 임시객체 사용
	
	logTime(goo, ref(n) ); // 최종 버전!!!!! 결국 참조로 보내려면 이렇게 합니다.
						   // C# : logTime( ref n)

	cout << n << endl;
}




/*
template<typename T> T square(T a) { return a * a; }

// 다음중 쉬운 코드는 ?
square(3);      // 1. T를 컴파일러가 추론 - 쉽다.
square<int>(3); // 2. T를 사용자가 결정 - 어려워 보인다.


list<int> s(10, 3); //10개를 3으로 초기화
*/











