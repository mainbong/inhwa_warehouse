// 13_template_alias - 51 page
#include <iostream>
using namespace std;

// ���� C, C++
typedef void(*PF)(int);

// C++11
using PF2 = void(*)(int);
using DWORD = int;


//typedef vector<int, MyAlloc<int>> MyVector;
// �Ʒ� ó�� �ϰ� �;����ϴ�. - template typedef.. �׷��� error.
template<typename T> typedef vector<T, MyAlloc<T>> MyVector;

MyVector<int> v;


// C++11�� template�� ��Ī�� �˴ϴ�.
template<typename T> using MyVector = vector<T, MyAlloc<T>>;
MyVector<int> v; // vector<int, MyAlloc<int>> 



int main()
{
	PF f1;
	DWORD n; // int n;

	vector<int, MyAlloc<int>> v; // �޸� �Ҵ��� �ʿ� �ϸ� MyAlloc�� ����ش޶�
								// �޸� �Ҵ�� ����.

}