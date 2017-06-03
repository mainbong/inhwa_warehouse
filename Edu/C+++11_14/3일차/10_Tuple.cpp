// 10_tuple
#include <iostream>
#include <typeinfo>
using namespace std;

// 1일차에서 가변인자템플릿 5.cpp   xtuple 2개 복사해오세요.. -

template<typename T, typename  ... Types>
class xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> BaseType;
public:
	T value;
	xtuple() {}
	xtuple(const T& v, const Types& ... args) : value(v), BaseType(args...) {}
	static const int N = BaseType::N + 1;
};

template<typename T> class xtuple<T>
{
public:
	T value;
	xtuple() {}
	xtuple(const T& v) : value(v) {}
	static const int N = 1;
};
//--------------------------------------------
// T 튜플에서 N의 타입을 구하는 traits
// T : 튜플
// N : 알고자 하는 요소의 index( 0 기반)
template<int N, typename T> struct GetType
{
};

// 타입을 구할수 있도록 부분 전문화 한다.
// 1. 0번째 타입만 생각해 봅시다.
/*
template<typename T > struct GetType<0, T>
{
	// T에서 0번째 타입을 구할수 없다. - 부분전문화를 잘못했다
};
*/
/*
template<typename T > struct GetType<0, xtuple<T>>
{
	// 인자가 한개인 tuple 만 사용할수 있는 모양이다 - 부분 전문화 잘못했다
};
*/

/*
template<typename ... Types > struct GetType<0, xtuple<Types...>>
{
	// 인자가 여러개인 tuple에 적용할수 있게 되었다.
	// 하지만 tuple<Types...>의 0번째 타입을 구할수 없다. - 잘못만들었다
};
*/
template<typename T, typename ... Types > 
struct GetType<0, xtuple<T, Types...>>
{
	typedef T type; // 1번째 요소 타입
	typedef xtuple<T, Types...> tupleType; // 튜플 타입
};

// N번째 타입 알아내기
template< int N , typename T, typename ... Types> 
struct GetType<N, xtuple<T, Types...>  > //: public GetType<N - 1, xtuple<Types...>>
{
	typedef typename GetType<N-1, xtuple<Types...>>::type  type;
	typedef typename GetType<N-1, xtuple<Types...>>::tupleType  tupleType;
};
/*
// 결국 get은 
template<int N, typename T> 
N번째 요소 타입&
xget(T& tp)
{
	return ((N번째요소를 가진 튜플 타입&)tp).value;
}
*/

template<int N, typename T>
typename GetType<N,T>::type&
xget(T& tp)
{
	return ((typename GetType<N,T>::tupleType&)tp).value;
}

template<typename T> void foo(T& tp) // T : tuple<int, double, char> 입니다.
{
	cout << xget<1>(tp) << endl;


	// tp가 가진 요소의 0번째 타입을 알아내 봅시다
//	typename GetType<1, T>::type  n; // n은 _int_타입
//	cout << typeid(n).name() << endl; // 
}


int main()
{
	xtuple<int, double, char> t(1, 3.3, 'a');

	foo(t);
}








