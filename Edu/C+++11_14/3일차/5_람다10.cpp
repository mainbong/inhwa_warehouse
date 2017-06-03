#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 람다와 리턴 타입 - 67 page
int main()
{
	auto f1 = [](int a, int b) { return a + b; };

	// trailing return, suffix return type syntax
	auto f2 = [](int a, int b) -> int { return a + b; };


	auto f3 = [](int a, int b) { if (a == 1) return a;
										else return b; };

	// 2개이상의 리턴문이 다른 타입을 리턴하면 반드시 trailing return을 표시해야한다.
	auto f4 = [](int a, int b) -> double { if (a == 1) return a;
											else return 3.4; };
}


