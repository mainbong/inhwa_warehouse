// 7_move7
#include <iostream>
#include <string>
using namespace std;

// move �����ڸ� ���鶧�� ��� ��� data �� move�� �ű⼼��!!
class Test
{
	char* name;
	string s;
public:
	Test(Test&& t) : name(t.name), s(move(t.s)) // �ʱ�ȭ����Ʈ..!
	{
		/*
		name = t.name;
		//s = t.s; // move ?copy �Դϴ�!!
		s = move(t.s); // move!!
		*/
		t.name = 0;
	}
};
// 79 page
int main()
{
	Test t1;		// t1 : lvalue
	Test t2 = move(t1); // t1�� eXpire �˴ϴ�. xvalue ��� �θ��ϴ�.

	t1 = move(t3);
					// 
}



