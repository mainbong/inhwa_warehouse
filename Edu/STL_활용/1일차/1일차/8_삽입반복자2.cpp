#include "show.h"

int main()
{
	list<int> s(5, 0);

	int x[5] = { 1,2,3,4,5 };

	// �����
	// copy(x, x + 5, s.begin());

	// ���� �߰��ϱ�
	// copy(x, x+5, back_inserter(s));

	// �տ� �߰��� ������.
	//copy(x, x + 5, front_inserter(s)); // front_insert_iterator<> �� ����


	// �߰��� �ֱ� : s �� 2��° �ֱ�
	//copy(x, x + 5, inserter(s, ++s.begin()));


	// ���� ������ ���� �տ� �ֱ�
	copy(x, x + 5, inserter(s, s.begin())); // 1 2 3 4 5 0 0 0 0 0
												// Ŭ���� ���� : insert_iterator<T>
	show(s);
}