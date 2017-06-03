// 4_예외안정성
#include "show.h"

// exception safety
// 1. 완전 보장 : 예외가 없다... int a = 0;
// 2. 강력 보장 : 예외가 있어도 처리하면 객체는 이전 상태를 보장한다. 사용가능
// 3. 기본 보장 : 예외가 있어도 자원 누수는 없다. 객체의 상태는 보장 안됨. 사용불가

template<typename T> class stack
{
	T buff[10];
	int index;

public:
	stack() : index(0) {}

	void	push(const T& a)	{ buff[index++] = a; }
	T		pop() 
	{ 
		--index;
		return buff[index]; 
	}
};

int main()
{
	stack<int> s;
	try { s.pop(); }
	catch (int n) {

	}
	// 프로그램을 계속 실행가능.. 그런데 s 객체를 사용할 수 있을까요 ?
}