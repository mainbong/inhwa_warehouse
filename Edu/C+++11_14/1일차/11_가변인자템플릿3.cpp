#include <iostream>
using namespace std;

// �������� ������ - �ٽ�!!! - 43 page 5��

// ��Ģ 1. ù��° ���� ��ŭ�� ������ Ÿ������ �޴´�.
// ��Ģ 2. recursive�� ���
// ��Ģ 3. ���Ḧ ���� ���� ���� �Լ� ����.

// ���� ! ��� ȣ�� ó�� �������� �ᱹ ������ ������ 3,2, 1���� �Լ��� �����ϴ°�.
int n = 0;

template<typename T, typename ... Types> 
void foo(T value, Types ... args)
{
	//static int n = 0;
	++n;

	cout << n << " : " << value << endl;
	foo(args...); // T : 2.2   args : 'a'
				  // T : 'a'   args : 
}
// ���Ḧ ���� ���ھ��� foo����
void foo() {}


int main()
{
	foo(1, 2.2, 'a'); // value : 1   args : 2.2, 'a'
}

