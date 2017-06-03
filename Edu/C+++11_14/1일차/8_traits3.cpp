// traits1�� �����ؿ�����
#include <iostream>
using namespace std;

template<typename T> struct IsPointer      { enum { value = false };};
template<typename T> struct IsPointer<T*>  { enum { value = true };};

template<typename T> void printv(T v)
{
	// C++ �����Ϸ��� ����
	// 1. ���� �Լ��� T�� Ÿ���� �����Ǹ� ���� �Լ� ���� => T�� int !!
	// 2. ������ �Լ� ������
	// 3. ������� ���� �κ� ����ȭ�ؼ� ����.
	if ( IsPointer<T>::value )		// if ( false ) �� �ڵ� ����
		cout << v << ", " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int    n = 3;
	printv(n); // 1. error �߻�.
	//printv(&n);// 2
}
// �����ϸ� ������ �ֽ��ϴ�. �� �������� �����غ����� . 1,2�߿����� ������ ?




