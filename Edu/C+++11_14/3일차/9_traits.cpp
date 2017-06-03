				// 9_traits
#include <iostream>
	using namespace std;

// Traits ����� ���
// 1. ������ �ð��� ����ϴ� �Լ�� -
// ��Ÿ �Լ�
// 2. ��κ� ���ø� ����� ���ü��
// �����Ѵ�.
// 3. primary template��� �Լ� ���� �����Ѵ�.

// 4. ���ϴ� ������ �κ� ��ȭ ����
// ������ �Ѵ�. => ���ø� ������
// ����� �ٲ��
// �ִ�.
// ���� ����ڴ� primary template ������
// ����ؾ� �Ѵ�.


// IsArray�� ���ڰ� �Ѱ��� ������
// ���ȴ�.
template < typename T > struct IsArray
{
	enum
	{ value = false };
};

template < typename T, int N > struct IsArray <T[N] >
{
	enum
	{ value = true };
};

template < typename T > void foo(const T & a)
{
	if (IsArray < T >::value)
		cout << "�迭�Դϴ�." << endl;
}

int main()
{
	int x[3] = { 1, 2, 3 };		// T[N]
	foo(x);
}