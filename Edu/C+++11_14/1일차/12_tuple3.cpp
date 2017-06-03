#include <iostream>
using namespace std;

template<typename T, typename  ... Types>
class xtuple : public xtuple<Types...>
{
	// 부모 타입을 보기 좋도록 typedef
	typedef xtuple<Types...> BaseType;
public:
	T value;

	// 생성자
	xtuple() {} // 디폴트 생성자
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



int main()
{
	xtuple<int, double, char> t3( 3, 4.4, 'a'); 
}









