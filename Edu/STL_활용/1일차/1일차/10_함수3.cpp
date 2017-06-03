// 10_함수3
#include "show.h"

int foo(int a, int b) 
{ 
	cout << "foo" << endl;
	return a + b; 
}

/*
template<typename T> struct Plus
{
	inline T operator()(T a, T b) { return a + b; } // 이미 제공한다!
};
*/
#include <functional> //STL 이 제공하는 함수 객체
/*
struct Plus
{
	inline int operator()(int a, int b) { return a + b; }
};
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 1,2,3,4,5 };

	vector<int> v(5, 0);

	// 일반 함수를 알고리즘 인자로 보내면 인라인 치환이 안된다.  - 느리다.
	// transform(x, x + 5,y, v.begin(), foo);

	// 함수객체를 사용하면 인라인 치환된다. - 빠르다.
	plus<int> p;
	transform(x, x + 5, y, v.begin(), p);

	show(v);
}