#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

// ���ٿ� �Լ� ���� - 66 page �Ʒ� �ڵ�
//void sort( int(*p)(int,int) ) // ���������� �ζ��� ġȯ �ȵ�

//void sort(function<int(int,int)> p ) // ���������� �ζ��� ġȯ �ȵ�

//void sort( auto p) //�ɱ�� ?? auto�� �Լ� ����Ÿ���� �ɼ� ����!! error

// ��� : ����ǥ������ ���ڷ� �������� ���ø��� �������!
// "�Լ������� T�� ���������� auto�� ������ �����Դϴ�.!"- �����ð�
template<typename T> void sort( T p) // ok.. �ζ��� ġȯ�� �ȴ�.!!
{
	cout << p(1, 2) << endl;
}

int main()
{
	sort( [](int a, int b) {return  a + b; } );
}


