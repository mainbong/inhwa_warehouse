// 2_nullptr
#include <iostream>
using namespace std;

void foo(int   n) { cout << "int" << endl; }   // 1
void foo(void* n) { cout << "void*" << endl; } // 2
void goo(char* p) { cout << "goo" << endl; }

// C++11������ ������ "������ 0" �� �ʿ� �߽��ϴ�.

int main()
{
	int* p1 = nullptr; // ok. 
//	int  n = nullptr;  // error. int�� �ƴ� ������ 0 �Դϴ�.

	foo(nullptr);
	goo(nullptr);

	// bool ��ȯ
	bool b = nullptr;  // if ( nullptr )
						// ok.. int�� ��ȯ �ɼ� ������ bool ��ȯ ����.
}






