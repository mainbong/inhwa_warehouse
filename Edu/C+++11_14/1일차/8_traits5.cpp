// traits1�� �����ؿ�����
#include <iostream>
using namespace std;

// �Ʒ� ���ø��� 2000�⿡ ���� ���� ������ ����Դϴ�.
// int2type : ������ �ð� ����� ���� �ٸ� Ÿ������ ����� ����
//				0,1,2���� ����� �Լ� �����ε��Ҽ� �ְԵȴ�.
template<int N> struct int2type
{
	enum { value = N};
};

/*
int main()
{
	foo(0);
	foo(1); // 0, 1 �� ���� Ÿ��(int)�̴�. foo(0), foo(1) ���� �Լ� ȣ��
	int2type<0> t0;
	int2type<1> t1;
	foo(t0);
	foo(t1); // t0�� t1�� �ٸ� Ÿ���̴�. foo(t0),foo(t1) �� �ٸ� �Լ� ȣ��
}
*/





template<typename T> struct IsPointer { enum { value = false }; };
template<typename T> struct IsPointer<T*> { enum { value = true }; };

//---------------------------------------------------------
template<typename T> void printvImp(T v, int2type<1> )
{
	cout << "�������� ���" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T v, int2type<0> )
{
	cout << "�����Ͱ� �ƴ� ���" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	// T�� ������ ������ ���� �Լ� �����ε� ���
	printvImp(v, int2type< IsPointer<T>::value >() );
}
int main()
{
	int    n = 3;
	printv(n);
	printv(&n);
}





