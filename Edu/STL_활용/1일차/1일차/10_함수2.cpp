//10_함수2
#include "show.h"

// 함수보다 함수 객체가 좋다.
// 함수 객체 : () 연산자를 재정의해서 함수처럼 사용가능한 객체
// 장점 : 1. 객체이므로 상태를 가질 수 있다. 일반 함수는 상태가 없다.
//			상태와 생성자를 잘 활용하면 재사용성이 좋아진다.

//		  2. 인라인 치환된다.

find_if(s.begin(), s.end(), foo); // foo 함수가 다시 호출될 때 치환 안됨

Modulus m(4);
find_if(s.begin(), s.end(), m); // m 함수객체가 다시 호출될 때 치환됨

struct Modulus
{
	int value;
	Modulus(int n) : value(n) {}
	int operator() (int a)
	{
		return a % value == 0;
	}
};

int main()
{
	Modulus m(3);
	bool b = m(4); // m.operator()(4)
	cout << b << endl;

	// a + b; // a.operator+(b)
	// a - b; // a.operator-(b)
	// a();   // a.operator()()
	// a(1);  // a.operator()(1)
}