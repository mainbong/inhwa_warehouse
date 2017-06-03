#include <iostream>
#include <algorithm>
using namespace std;

// 람다표현식(Lambda Express) : 함수 객체를 만드는 표현식

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// [] : Lamda Introducer, 람다가 시작됨을 알리는 표시
	sort(x, x + 10, [](int a, int b) { return a < b; });

	// 위 한줄은 컴파일 하면 - 65page
	// 클로져(Closure) : 람다 표현식을 통해서 컴파일러가 만든 클래스
	class Closure_Object
	{
	public:
		inline int operator()(int a, int b) const 
		{
			return a < b; 
		}
	};
	
	sort(x, x + 10, Closure_Object() );
}








