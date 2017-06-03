//10_begin_end - 19 page �׸�2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// �����̳� ����.
template<typename T> void showImp(T& c, false_type) // �迭�� �ƴҶ�
{
	auto p = c.begin();
	while (p != c.end())
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}
// �迭 ����
template<typename T> void showImp(T& c, true_type) 
{
	auto p = c; // �迭�� �̸��� �ּ��̴�

	while (p != c + extent<T, 0>::value ) // extent<T, 0>::value  T�迭��0��°ũ��
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

template<typename T> void show(T& c)
{
	// �迭������ �����ؼ� �Լ� �����ε� ���
	showImp(c, is_array<T>() );
}


int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);
	show(x);
}