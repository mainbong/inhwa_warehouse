// 2_복사금지스마트포인터
#include "show.h"
#include <memory>

int main()
{
	shared_ptr<int> p1(new int); // 자원 + 관리객체 생성.
	shared_ptr<int> p2 = p1;

	unique_ptr<int> up1(new int); // 관리객체가 없다.
								// 소멸자에서 delete 기능만 제공.
	//unique_ptr<int> up2 = up1; // error

	unique_ptr<int> up2 = move(up1); // 복사는 안되지만 move 는 된다. move 는 포인터를 넘기고 자신은 지워버리니까

	*up2 = 10;

	cout << *up2 << endl; // ok...

	//*up1 = 10; // runtime error - up1은 자원이 up2에 전달되었다.!!

	cout << sizeof(up2) << endl; // 사이즈가 실제 포인터와 같네! 기계어코드로는 실제포인터와 다를바가 없다. 따라서 성능저하가 없다.
}