// 10_함수3
#include "show.h"

int foo(int a, int b)
{
	cout << "foo" << endl;
	return a + b;
}

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 1,2,-3,4,5 };

	vector<int> v(5, 0);

	// 1. 일반 함수	
	// transform(x, x + 5,y, v.begin(), foo);

	// 2. 함수 객체.
	// plus<int> p;
	// transform(x, x + 5, y, v.begin(), p);

	// transform(x, x + 5, y, v.begin(), plus<int>()); // 클래스이름() : 임시객체생성, 문장의 끝에서 파괴

	// 3. C++11 의 람다 표현식 문법
	transform(x, x + 5, y, v.begin(), [](int a, int b) {return a + b;});

	show(v);
}