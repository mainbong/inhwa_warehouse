// 9_static_assert - 12 page 항목 2-1
#include <iostream>
#include <cassert>
using namespace std;

void foo(int age)
{
	// 함수의 인자는 바로 사용하지 말고
	// 인자의 유효성을 먼저 확인하는 것이 좋다.
	assert(age > 0);  // 기존 C의 assert() : runtime 에 동작


	//C++11 컴파일 시간 assert 도입
	static_assert(sizeof(int) >= 8, "int가 8바이트 이상인 시스템만 컴파일가능");


	char* p = new char[age];
}

int main()
{
	foo(-10);
}

