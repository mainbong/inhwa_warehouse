// 2_nullptr
#include <iostream>
using namespace std;

void foo(int   n) { cout << "int" << endl; }   // 1
void foo(void* n) { cout << "void*" << endl; } // 2
void goo(char* p) { cout << "goo" << endl; }

int main()
{
	foo(0); // 1
	foo((void*)0); // 2

#define NULL (void*)0
	foo(NULL);

	goo(NULL); // C   : void* => �ٸ� Ÿ��* �� �Ͻ��� ��ȯ ���
			   // C++ : void* => �ٸ� Ÿ��* �� �Ͻ��� ��ȯ ���ȵ� 
}








/*
int main()
{
	// 0�� ��ü�� ? int Ÿ��, ��� Ÿ���� �����ͷ� �Ͻ��� ����ȯ�ȴ�.
	int  n = 0;
	int* p1 = 0;
	int* p2 = 10; // error. 0�ܴ̿� �����ͷ� �Ͻ��� ����ȯ �ȵ�.
}
*/