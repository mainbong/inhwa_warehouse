//10_begin_end - 19 page �׸�2-3

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// C++11�� ���� - �Ϲ� �Լ� begin�� ��������
/*
template<typename T> auto begin(T& c) { return c.begin(); }
template<typename T> auto end(T& c)   { return c.end(); }

// �迭������ �Ϲ� �Լ� begin()�� ��������.
template<typename T, int N> T* begin(T(&arr)[N]) { return arr; }
template<typename T, int N> T* end  (T(&arr)[N]) { return arr+N; }
*/

// �˰��� �Լ� ���鶧 �ݺ��ڸ� ������ 2���� ���
// 1. c.begin() : STL �����̳ʸ� ��밡��. �迭�� �ȵȴ�
// 2. begin(c)  : STL �����̳� + �迭, ��� ��밡��

// ��� �Լ� ���ٴ� �Ϲ��Լ� begin()�� �������!!


template<typename T> void show(T& c)
{
	//auto p = c.begin();
	auto p = begin(c);

	while (p != end(c) )
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	show(v);
	show(x);
}