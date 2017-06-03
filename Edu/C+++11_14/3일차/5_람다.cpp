// 5_람다 - 64page ~
#include <iostream>
using namespace std;

// 함수객체 개념
// () 연산자를 재정의 해서 함수 처럼 사용가능한 객체(Function Object, Functor)
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(1, 2); // p.operator()(1,2)
	cout <<  n << endl; // 3
}




