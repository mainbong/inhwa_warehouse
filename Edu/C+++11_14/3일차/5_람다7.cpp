#include <iostream>
#include <typeinfo>
using namespace std;

//람다와 타입 - 65page 3번
// 모든 람다는 다른 타입이다(함수객체이므로)
int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	// RTTI를 사용하면 특정 변수의 타입이름을 출력할수 있습니다.
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
}


