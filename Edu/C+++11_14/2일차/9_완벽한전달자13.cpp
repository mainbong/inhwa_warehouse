#include <iostream>
#include <stdio.h>
using namespace std;

void goo(int a, int b, int c)
{
	printf("%d, %d, %d\n", a, b, c);
}

int hoo(int a) { return -a; }

template<typename ... Types> void foo(Types ... args)
{
	goo(args...); // goo(1,2,3)
	//hoo(args...); // error. hoo�� ���ڰ� �Ѱ��Դϴ�.

	goo(hoo(args)...);// goo(hoo(args'�� 1��), hoo(args'2), hoo(args'3))
}

int main()
{
	foo(1, 2, 3); // args : 1,2,3
}