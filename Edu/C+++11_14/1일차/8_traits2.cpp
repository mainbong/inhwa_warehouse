// 8_traits2
#include <iostream>
using namespace std;

// T�� ������ ���� �����ϴ� ���

// traits ����� ����� �ٽ� 
// primary template : false ����(value = false)��� �ǹ�
// �κ� ����ȭ ���� : true ����(value = true)��� �ǹ�

// ������ �ð��� T�� ���� �����ؼ� �˰����� �����ϰ� �ϴ� ������ ��Ÿ �Լ�!!

template<typename T> struct IsPointer
{
	enum { value = false };
};
template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};
template<typename T> void foo(const T& a)
{
	if ( IsPointer<T>::value ) // ����ü�̸�::enum���
		cout << "������ �Դϴ�" << endl;
	else
		cout << "�����Ͱ� �ƴմϴ�." << endl;
}
int main()
{
	int n = 10;
	foo(n);

	foo(&n);
}
