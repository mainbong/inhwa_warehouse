#include <iostream>
using namespace std;

// �Ʒ� ����� 100������ traits(��Ÿ�Լ�)�� �ֽ��ϴ�.
#include <type_traits>

template<typename T> void fooImp(const T& a, true_type) 
{ 
	cout << "fooImp true_type" << endl;
	*a = 10; 
}

template<typename T> void fooImp(const T& a, false_type)
{
	//*a = 10; 
	cout << "fooImp false_type" << endl;
}

template<typename T> void foo(const T& a)
{
	// a�� Ư���� ���� �˰����� �ٲٰ� �ʹٸ�
	// 1. value�� if������ �����Ѵ�.
	//	  ����, a�� �����Ͷ� *a ǥ���� ����Ҽ� ����.
	if (is_pointer<T>::value)
		cout << "������ �϶� �˰���" << endl; // *a
	else
		cout << "������ �ƴҶ� �˰���" << endl;

	// 2. *a ���� ǥ���� �ʿ��ϸ� - �Լ� �����ε� ���
	fooImp( a, is_pointer<T>() );
}


int main()
{
	int n = 10;
	foo(&n);
}






