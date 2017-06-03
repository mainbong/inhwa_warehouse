// 9_���������̳�

#include "show.h"
#include <set>

int main()
{
	typedef set<int, greater<int>> SET;
	SET s;	// RB(red black) Tree
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(20);	
	s.insert(40);

	pair<SET::iterator, bool> ret =s.insert(20); // ����� ���ϰ��� pair�ε�, first �� �ݺ���, second �� ���������̴�.
	if (!ret.second)
	{
		cout << "������ ��Ұ� �ֽ��ϴ�." << endl;
	}

	// �Ʒ� �ڵ带 ���غ�����
	//SET::iterator p2 = find(s.begin(), s.end(), 20); // ã�� ���� �ִµ� RB-Tree �������� �����˻��ϰ� �ں�����.
													// Ʈ���� binary ��ġ�� ������.
	auto p2 = s.find(20);	// �̰� ����� ���̳ʸ� ��ġ��.
	cout << *p2 <<"�� ã�ҽ��ϴ�."<< endl;
	
	//	set<int>::iterator p= s.begin(); // ���� ���� ���..
	SET::iterator p = s.begin(); // �������� �������ϲ�.. �ٵ� auto�� ¯
	while (p != s.end())
	{
		cout << *p << endl;
		++p; // inorder ��ȸ...
	}
}