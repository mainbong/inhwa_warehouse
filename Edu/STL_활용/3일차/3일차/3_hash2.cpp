// 3_hash
#include "show.h"
#include <set> // RB Tree
#include <unordered_set> // hash

int main()
{
	unordered_set<int> s; // set<> �� ������ ���� ����.
	s.insert(10);
	s.insert(30);
	s.insert(15);
	s.insert(20);

	auto ret = s.insert(20);

	if (ret.second == false)
		cout << "����" << endl;

	// s ���� 30�� ã�Ƽ� ����غ�����.
	unordered_set<int>::iterator p = s.find(30); // hash�Լ��� ����ؼ� �˻�
	cout << *p << endl; // 30
}