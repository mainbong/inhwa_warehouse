// 8_auto3

// auto는 함수인자는 안되지만 람다 인자는 가능합니다.

//void foo(auto n) {} // error

int main()
{
	auto f = [](auto a, auto b) { return a + b; };

	int n = f(1, 2); 

	// 원리 - 람다의 auto인자는 클로져의 ()연산자 함수를 템플릿으로 생성!
	class Closure_Object
	{
	public:
		template<typename T1, typename T2> 
		decltype(auto) operator()(T1 a, T2 b) { return a + b; }
	};
}






