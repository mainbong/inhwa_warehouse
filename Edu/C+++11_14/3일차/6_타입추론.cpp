// 6_Ÿ���߷� - 92 ~ 
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T> class TD; // ���� �Ѵ�.


template<typename T> void foo(T a)
{
	// T�� Ÿ���� �˰� �ʹٸ� - ��Ȯ���� �ʴ�!!
//	cout << typeid(T).name() << endl;

//	TD<T> a; //  ���� �����Ƿ� ���� �߻�. �����޼����� ���� T�� �˼� �ִ�

	// boost�� type_index ���̺귯�� ��� - ���� ��Ȯ������.. ���������� �ʴ�.
	// ���� 90page ���� ����
}


int main()
{
	int n = 0;
	const int& r = n;

	foo(n); // T �� int

	foo(r); // T ? int ? int& ? const int& ? const int
}






