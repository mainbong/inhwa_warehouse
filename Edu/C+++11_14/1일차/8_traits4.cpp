// traits1�� �����ؿ�����
#include <iostream>
using namespace std;

template<typename T> struct IsPointer { enum { value = false }; };
template<typename T> struct IsPointer<T*> { enum { value = true }; };

// T�� ������ �� ���� �׷��� ���� ��쿡 ó���� �Լ��� 2�� �����. - �����ε�
template<typename T> void printvImp(T a, YES)
{
	cout << "�������� ���" << endl;
	cout << v << ", " << *v << endl;
}
template<typename T> void printvImp(T a, NO)
{
	cout << "�����Ͱ� �ƴ� ���" << endl;
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	// T�� ������ ������ ���� �Լ� �����ε� ���
	printvImp(v, ? ? );

	// �Լ� �����ε��� ���� �Լ� ���� : ������ �ð��� �����˴ϴ�.
	//						�������� ���� �Լ����ø��� �ν��Ͻ�ȭ ���� �ʽ��ϴ�.

	// if���� ���� �Լ� ���� : ����ð��� �����˴ϴ�.
	//						�Ʒ� �ڵ尡 ������ �ð��� true�� ���͵�
	//						�ᱹ ȣ���� ����ð� �̹Ƿ�
	//						printvImp(YES), printvImp(NO) ������
	//						��� �ν��Ͻ�ȭ(���� �Լ��� ����°�)�� �˴ϴ�.
	//						�׷�, int�� v�� *v�ϹǷ� �ٽ�error


	/*
	if (IsPointer<T>::value)		
		printvImp(v, YES);
	else
		printvImp(v, NO);
	*/
}


int main()
{
	int    n = 3;
	printv(n); 
	//printv(&n);
}





