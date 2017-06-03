// 1_Hello.cpp
#include <iostream>
#include <complex>
#include <chrono>
using namespace std;
using namespace std::chrono;

// C++11 미리 보기.! - 3 page 2번
int main()
{
	int n1 = 0b10;      // Binary Literal
	int n2 = 1'000'000; // Digit Separator

	cout << n1 << endl; // 2
	cout << n2 << endl;

	double x[5] = { 1,2,3,4,5 };

	auto n3 = x[0]; // 컴파일러가 우변의 타입을 조사해서 좌변을 결정해달라

	decltype(n3) n4 = n3; // n3와 같은 타입의 변수 n4를 만들어 달라
						  // gcc의 typeof()개념.


	float f = 3.4f; // f : float를 나타내는 접미사..
					// f, l, s 등

	// user define literal 문법
	minutes m2 = 3min;

	cout << m2.count() << endl;


	complex<int> c1(3);

	cout << c1 << endl; // 3 + 0i


	complex<int> c2(3i); // i도 생겼습니다.

	cout << c2 << endl; // 0 + 3i

	
	for (int i = 0; i < 5; i++)
	{
		double d = x[i];
	}

	// C++11 ranged for
	for ( auto d : x)  // C# java 의 foreach()개념.
	{
		cout << d << endl;
	}
}










// 컴파일  + 실행 : Ctrl + F5
// 컴파일만 : Ctrl + Shift + B







