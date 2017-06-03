#include <iostream>
using namespace std;

// C++11���� int2type�� �������Ѽ� �Ʒ� ���ø��� �����մϴ�.
/*
template<typename T, T N> struct integral_constant
{
	static const T value = N; // enum ��� static const ���� ���
};
integral_constant<int, 0> n0;
integral_constant<int, 1> n1;
integral_constant<short, 0> s0;

// true/false           : �� ������ ��Ÿ���� ��, ���� Ÿ��
// true_type/false_type : �� ������ ��Ÿ���� Ÿ��, �ٸ� Ÿ��
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// ���� traits �� C++ ǥ�ؿ� 100���� �ֽ��ϴ�.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};
*/

#include <type_traits> // �� �ȿ� ���� ��� �ڵ尡 �ֽ��ϴ�.

//-----------------------------------------------------------
template<typename T> void printvImp(T v, true_type )
{
	cout << "�������� ���" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T v, false_type)
{
	cout << "�����Ͱ� �ƴ� ���" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	printvImp(v, is_pointer<T>() );
}


int main()
{
	int    n = 3;
	printv(n);
	printv(&n);
}


