// traits1번 복사해오세요
#include <iostream>
using namespace std;

// 아래 템플릿이 2000년에 만든 아주 유명한 기술입니다.
// int2type : 컴파일 시간 상수를 서로 다른 타입으로 만드는 도구
//				0,1,2등의 상수로 함수 오버로딩할수 있게된다.
template<int N> struct int2type
{
	enum { value = N};
};

/*
int main()
{
	foo(0);
	foo(1); // 0, 1 은 같은 타입(int)이다. foo(0), foo(1) 같은 함수 호출
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1); // t0와 t1은 다른 타입이다. foo(t0),foo(t1) 은 다른 함수 호출
}
*/





template<typename T> struct IsPointer { enum { value = false }; };
template<typename T> struct IsPointer<T*> { enum { value = true }; };

//---------------------------------------------------------
template<typename T> void printvImp(T v, int2type<1> )
{
	cout << "포인터인 경우" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T v, int2type<0> )
{
	cout << "포인터가 아닌 경우" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	// T가 포인터 인지에 따라 함수 오버로딩 사용
	printvImp(v, int2type< IsPointer<T>::value >() );
}
int main()
{
	int    n = 3;
	printv(n);
	printv(&n);
}





