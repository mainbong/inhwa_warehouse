#include <iostream>
using namespace std;

// 가변인자 꺼내기 - 핵심!!! - 43 page 5번

// 규칙 1. 첫번째 인자 만큼은 독립된 타입으로 받는다.
// 규칙 2. recursive를 사용
// 규칙 3. 종료를 위해 인자 없는 함수 제공.

// 주의 ! 재귀 호출 처럼 보이지만 결국 인자의 갯수가 3,2, 1개인 함수를 생성하는것.
int n = 0;

template<typename T, typename ... Types> 
void foo(T value, Types ... args)
{
	//static int n = 0;
	++n;

	cout << n << " : " << value << endl;
	foo(args...); // T : 2.2   args : 'a'
				  // T : 'a'   args : 
}
// 종료를 위해 인자없는 foo제공
void foo() {}


int main()
{
	foo(1, 2.2, 'a'); // value : 1   args : 2.2, 'a'
}

