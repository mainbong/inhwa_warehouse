// 4_예외안정성
#include "show.h"

template<typename T> class stack
{
	T buff[10];
	int index;

public:
	stack() : index(0) {}

	void	push(const T& a) { buff[index++] = a; }
	T		pop() 
	{
		if (index < 1) throw 1;
		--index;
		return buff[index]; 
	}
};

class People
{

};

int main()
{
	stack<People> s;
	People p;
	s.push(p);

	try 
	{ 
		//People p2 = s.pop();	// 1. pop() 실행 - 아무 문제 없다
								// 2. People 복사 생성자 실행
								// - 여기서 예외가 나오면 ? 노답!! 절대 제거와 뽑기를 동시에 하면 안되겠다...
		People p2 = s.top(); // 복사 생성자 예외가 있어도
							 // 객체는 stack 에 남아 있습니다.
	}
	catch (... n) {

	}
	// 프로그램을 계속 실행가능.. 그런데 s 객체를 사용할 수 있을까요 ?
}