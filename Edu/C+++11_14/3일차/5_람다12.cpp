#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// 람다와 지역변수 캡쳐 - 68 page
int main()
{
	int v1 = 10;
	int v2 = 20;
	//auto f1 = [=](int a) { v1 = 0;  return a + v1; }; // error
	// mutable 람다!!. 지역변수를 캡쳐한 멤버 변수가 mutable이다
	auto f1 = [=](int a) mutable { v1 = 0;  return a + v1; };
							// v1 = 0은 원본(지역변수)이 아닌 복사본이 
							// 변경되는 것입니다.
	f1(5);
	cout << v1 << endl;// 10 

/*
	// 지역변수 캡쳐의 원리(=)
	class Closure_Object
	{
		mutable int v1;
		mutable int v2;
	public:
		Closure_Object(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 0;
			return v1 + a;
		}
	};
	Closure_Object(v1, v2); // 결국 지역변수의 값을 멤버 변수에 보관하는것
*/
}

// www.cppreference.com



