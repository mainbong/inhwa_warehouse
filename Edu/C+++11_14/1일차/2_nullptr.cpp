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

	goo(NULL); // C   : void* => 다른 타입* 로 암시적 변환 허용
			   // C++ : void* => 다른 타입* 로 암시적 변환 허용안됨 
}








/*
int main()
{
	// 0의 정체는 ? int 타입, 모든 타입의 포인터로 암시적 형변환된다.
	int  n = 0;
	int* p1 = 0;
	int* p2 = 10; // error. 0이외는 포인터로 암시적 형변환 안됨.
}
*/