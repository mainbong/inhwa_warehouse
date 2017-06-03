#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 람다와 지역변수 캡쳐 - 68 page
int main()
{
	int v1 = 10;
	int v2 = 20;

	// 원본인 지역변수가 변경되게 하려면 아래 처럼 하면 됩니다
	//auto f1 = [&v1](int a) { v1 = 0;  return a + v1; };
	
	auto f1 = [&](int a) { v1 = 0;  return a + v1; };

	f1(5);
	cout << v1 << endl; // 0

	/*
	// 지역변수 캡쳐의 원리(&)
	class Closure_Object
	{
		int& v1;
		int& v2;
	public:
		Closure_Object(int& a, int& b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 0;
			return v1 + a;
		}
	};
	Closure_Object(v1, v2); // 결국 지역변수의 값을 멤버 변수에 보관하는것
	*/
}




