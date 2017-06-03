// 7_chrono
#include "show.h"
#include <chrono>
using namespace std::chrono;	// 시간, 타이머 등을 위한 C++ 표준 라이브러리
								// C++11 에서 추가

/*
template<int N1, int N2> struct ratio
{
	static const int num = N1; // 분자
	static const int den = N2; // 분모
};
*/
int main()
{
	ratio<1, 2> r1; // 1/2
	cout << r1.num << endl;
	cout << r1.den << endl;

	ratio<5, 10> r2; // 1/2
	cout << r2.num << endl;
	cout << r2.den << endl;

	//typedef ratio<1, 1000> milli;
	milli m;
	cout << m.num << endl;
	cout << m.den << endl;
}