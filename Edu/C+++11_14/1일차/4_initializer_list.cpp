// 4_initializer_list- 32 page
#include <iostream>
using namespace std;
/*
void foo(initializer_list<int> e)
{
	// 요소접근은 STL과 유사하게 사용하면 됩니다.
	// 반복자 : 요소를 가르키는 포인터라고 생각하면 됩니다.
	initializer_list<int>::iterator p = e.begin();

	while (p != e.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/

/*
void foo(initializer_list<int> e)
{
	auto p = e.begin();

	while (p != e.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/

void foo(initializer_list<int> e)
{
	// ranged for
	for (auto n : e)
		cout << n << endl;
}


int main()
{
	// 동일 타입에 대한 배열과 유사한 집합 객체.
	initializer_list<int> e = { 1,2,3,4 };
	foo(e);
	
//	foo({ 1,2,3,4,5 }); // C++98에서는 불가능했던 C++11의 새로운 표현
}






