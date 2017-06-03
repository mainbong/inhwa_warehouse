#include <iostream>
using namespace std;

// 임시객체와 lvalue!!

struct Point { int x, y; };

Point p = { 1, 2};

//Point foo()  : 값 리턴 : 임시객체 리턴, 함수호출이 lvalue가 될수 없다.
Point& foo()  // 참조리턴 : 임시객체를 만들지 말라, 함수 호출이 lvalue 가 될수있다.
{
	return p; // 이순간 p의 복사본인 임시객체가 리턴된다.
}  

int main()
{
	foo().x = 10; // VC++에서는 컴파일 되지만 gcc, clang 에서는 컴파일 에러발생
				  // 임시객체는 =의 왼쪽에 올수 없다.(lvalue가 될수 없다)

	cout << p.x << endl; // 1
}





