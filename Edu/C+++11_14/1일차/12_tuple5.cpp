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



int main()
{
	//      부모 xtuple<char>     // char value;
	// 부모  xtuple<double, char> // double value 보관
	xtuple<int, double, char> t3(1, 4.4, 'a'); // int value 보관.

	cout << t3.value << endl; // 1
	cout << ((xtuple<double, char>&)t3).value << endl; // 4.4
	cout << ((xtuple<char>&)t3).value << endl; // 'a'
}









