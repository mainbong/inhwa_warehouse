// 13_template_alias - 51 page
#include <iostream>
using namespace std;

// 기존 C, C++
typedef void(*PF)(int);

// C++11
using PF2 = void(*)(int);
using DWORD = int;


//typedef vector<int, MyAlloc<int>> MyVector;
// 아래 처럼 하고 싶었습니다. - template typedef.. 그런데 error.
template<typename T> typedef vector<T, MyAlloc<T>> MyVector;

MyVector<int> v;


// C++11은 template의 별칭도 됩니다.
template<typename T> using MyVector = vector<T, MyAlloc<T>>;
MyVector<int> v; // vector<int, MyAlloc<int>> 



int main()
{
	PF f1;
	DWORD n; // int n;

	vector<int, MyAlloc<int>> v; // 메모리 할당이 필요 하면 MyAlloc을 사용해달라
								// 메모리 할당기 개념.

}