// 7_move7
#include <iostream>
#include <string>
using namespace std;

// move 생성자를 만들때는 모든 멤버 data 를 move로 옮기세요!!
class Test
{
	char* name;
	string s;
public:
	Test(Test&& t) : name(t.name), s(move(t.s)) // 초기화리스트..!
	{
		/*
		name = t.name;
		//s = t.s; // move ?copy 입니다!!
		s = move(t.s); // move!!
		*/
		t.name = 0;
	}
};
// 79 page
int main()
{
	Test t1;		// t1 : lvalue
	Test t2 = move(t1); // t1은 eXpire 됩니다. xvalue 라고 부릅니다.

	t1 = move(t3);
					// 
}



