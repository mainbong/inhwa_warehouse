// 2_nullptr
#include <iostream>
using namespace std;

void foo(int   n) { cout << "int" << endl; }   // 1
void foo(void* n) { cout << "void*" << endl; } // 2
void goo(char* p) { cout << "goo" << endl; }

// C++11에서는 완전한 "포인터 0" 이 필요 했습니다.

int main()
{
	int* p1 = nullptr; // ok. 
//	int  n = nullptr;  // error. int가 아닌 포인터 0 입니다.

	foo(nullptr);
	goo(nullptr);

	// bool 변환
	bool b = nullptr;  // if ( nullptr )
						// ok.. int로 변환 될수 없지만 bool 변환 가능.
}






