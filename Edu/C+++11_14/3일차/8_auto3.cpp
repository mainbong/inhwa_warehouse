// 8_auto3

// auto�� �Լ����ڴ� �ȵ����� ���� ���ڴ� �����մϴ�.

//void foo(auto n) {} // error

int main()
{
	auto f = [](auto a, auto b) { return a + b; };

	int n = f(1, 2); 

	// ���� - ������ auto���ڴ� Ŭ������ ()������ �Լ��� ���ø����� ����!
	class Closure_Object
	{
	public:
		template<typename T1, typename T2> 
		decltype(auto) operator()(T1 a, T2 b) { return a + b; }
	};
}






