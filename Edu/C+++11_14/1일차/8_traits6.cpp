#include <iostream>
using namespace std;

// C++11에는 int2type을 발전시켜서 아래 템플릿을 제공합니다.
/*
template<typename T, T N> struct integral_constant
{
	static const T value = N; // enum 대신 static const 문법 사용
};
integral_constant<int, 0> n0;
integral_constant<int, 1> n1;
integral_constant<short, 0> s0;

// true/false           : 참 거짓을 나타내는 값, 같은 타입
// true_type/false_type : 참 거짓을 나타내는 타입, 다른 타입
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// 각종 traits 도 C++ 표준에 100여개 있습니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/

#include <type_traits> // 이 안에 위의 모든 코드가 있습니다.

//-----------------------------------------------------------
template<typename T> void printvImp(T v, true_type )
{
	cout << "포인터인 경우" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T v, false_type)
{
	cout << "포인터가 아닌 경우" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	printvImp(v, is_pointer<T>() );
}


int main()
{
	int    n = 3;
	printv(n);
	printv(&n);
}


