#include <iostream>
using namespace std;

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

// Tuple T의 N번째 요소의 타입을 구하는 메타 함수
template<int N, typename T> struct xtuple_element {};


// N이 0일때를 위한 부분 전문화..
template<typename T, typename ... Types> 
struct xtuple_element<0, xtuple<T, Types...>>
{
	typedef T type;
	typedef xtuple<T, Types...> tupleType; // 0번째 요소를 가진 튜플 모양
};
// N이 0이 아닐때
template<int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...>> 
	: public xtuple_element<N-1, xtuple< Types... >>
{
};

template<int N, typename T>
typename xtuple_element<N, T>::type&
xget(T& tp)
{
	return ((typename xtuple_element<N, T>::tupleType&)tp).value;
}



//사용법.
//xtuple_element<0, 튜플>::type; 
//xtuple_element<3, 튜플>::type;

/*
// tuple T에서 N번째 요소의 값을 꺼내는 함수
template<int N, typename T> 
T에 있는 N번째 요소타입& 
xget(T& tp)
{
	return ((N번째부모타입&)tp).value;
}
*/
int main()
{
	//      부모 xtuple<char>     // char value;
	// 부모  xtuple<double, char> // double value 보관
	xtuple<int, double, char> t3(1, 4.4, 'a'); // int value 보관.



	// t3 튜플에서 1번째 값을 꺼내는 함수
	double d = xget<1>(t3);

	cout << d << endl;
}









