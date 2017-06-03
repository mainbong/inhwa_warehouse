#include <iostream>
using namespace std;


struct Point { int x, y; };

Point p = { 1, 2 };

Point  foo() { return p; }
Point& goo() { return p; }

// 76 page 에 정리되어 있습니다. - 제목 "rvalue vs lvalue"로 수정해 주세요
// rvalue : =의 오른쪽에만 가능.       이름이 없다. 순간적으로 존재
//			값을 리턴하는 함수
// lvalue : =의 왼쪽, 오른쪽 모두 가능.이름이 있다. 일정기간 메모리에 지속
//			참조를 리턴하는 함수

int main()
{
	int n1 = 0;
	int n2 = 0;
	10 = n1; // error. 10은 =의 오른쪽만 가능하다. rvalue 
	n1 = 10; // ok. n1 은 lvalue
	n2 = n1; //

	foo().x = 10; // error
	goo().x = 10; // ok
}





