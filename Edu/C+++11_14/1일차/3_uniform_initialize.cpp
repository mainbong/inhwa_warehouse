// 3_uniform_initialize - 29page
#include <iostream>
using namespace std;

struct Point { int x, y; };
class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};
int main()
{
	// 기존 C++에서 객체를 초기화 하는 방법.
	/*
	int n1 = 0;
	int n2(0);

	int x[10] = { 1,2 };
	Point p = { 1,1 };
	Complex c(0, 0);
	*/
	//--------------------------------
	// C++11 초기화 기술 => {} 사용
	// "Uniform Initialize" 라는 문법.
	int n1 = { 0 };
	int n2{ 0 };

	int x[10]{ 1,2 };
	Point p { 1,1 };
	Complex c{ 0, 0 };

	int n3 = 3.4; // ok.. 버그의 원인
//	int n4{ 3.4 };// error. prevent narrow


//	char c3{ 300 }; // error. 300은 1byte로 표현 안됨..

}




