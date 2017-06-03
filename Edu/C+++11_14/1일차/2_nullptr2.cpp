// 2_nullptr
#include <iostream>
using namespace std;

void foo(int   n) { cout << "int" << endl; }   // 1
void foo(void* n) { cout << "void*" << endl; } // 2
void goo(char* p) { cout << "goo" << endl; }
/*
// 현재 NULL은 정확히 아래 처럼 구현되어 있습니다. - 15page 아래소스입니다.
#ifdef __cplusplus
	#define NULL	0
#else
	#define	NULL	(void*)0
#endif
*/
int main()
{
	goo(NULL); // ok..
	foo(NULL); // 1호출.. 버그발생.!
}






