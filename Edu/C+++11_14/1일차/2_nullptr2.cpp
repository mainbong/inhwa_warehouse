// 2_nullptr
#include <iostream>
using namespace std;

void foo(int   n) { cout << "int" << endl; }   // 1
void foo(void* n) { cout << "void*" << endl; } // 2
void goo(char* p) { cout << "goo" << endl; }
/*
// ���� NULL�� ��Ȯ�� �Ʒ� ó�� �����Ǿ� �ֽ��ϴ�. - 15page �Ʒ��ҽ��Դϴ�.
#ifdef __cplusplus
	#define NULL	0
#else
	#define	NULL	(void*)0
#endif
*/
int main()
{
	goo(NULL); // ok..
	foo(NULL); // 1ȣ��.. ���׹߻�.!
}






