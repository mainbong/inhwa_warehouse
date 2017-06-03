#include <iostream>
using namespace std;

// tuple 만들기 - 45 page
// 1. 가변인자 템플릿으로 해야 한다.
// 2. 첫번째 템플릿 인자는 독립적인 타입으로 받아야 한다.

template<typename T, typename  ... Types> 
class xtuple : public xtuple<Types...>
{
public:
	T value;

	static const int N = xtuple<Types...>::N + 1;  // 부모::N + 1
};

// xtuple이 템플릿 인자 한개 일때를 위한 부분 전문화
template<typename T> class xtuple<T>  // 인자가 한개 일때!!
{
public:
	T value;

	static const int N = 1; // 요소의 갯수
};

int main()
{
	//      부모 xtuple<char>     // char value;
	// 부모  xtuple<double, char> // double value 보관
	xtuple<int, double, char> t3; // int value 보관.
}









