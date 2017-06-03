#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 66 page
int main()
{
	// 람다는 저장하는 방법
	auto f1 = [](int a, int b) { return a + b; };
	//f1 = [](int a, int b) { return a + b; };// error 위 람다와아래 람다는 다른
											// 타입이다. 다른타입변수에 대입안됨

	int(*f2)(int,int) = [](int a, int b) { return a + b; };

	function<int(int,int)> f3 = [](int a, int b) { return a + b; };
	//f3 = &foo
	// 다음중 인라인 치환되는 것은 ?
	int n1 = f1(1, 2); // 치환 가능.!
	int n2 = f2(1, 2); // 치환 안됨
	int n3 = f3(1, 2); // 치환 안됨
}


