// 2_��������
#include "show.h"
#include <set> // STL�� set, RB tree �Դϴ�.

/*
template<typename T, typename Pred = less<T>> class set
{
	Pred pred; // �� ��å�� ���� �Լ� ��ü.
public:
	// �׳� ���ϸ� Ȯ�强�� ��������.
	// �Լ� �����ͷ� ���Լ��� ������ inline ġȯ�� �ȵǼ� �������ϰ� ���ϴ�
	// ���� STL �� ���ø��� �����
	void insert(const T& a)
	{
		//if (������� > a)
		if ( pred(�������, a))
			���ʿ� �ֱ�;
		else
			�����ʿ� �ֱ�;
	}
}
*/
int main()
{
	set<int, greater<int>> s; // greater : > ����

	s.insert(10);
	s.insert(15);
	s.insert(20);
	s.insert(13);
	s.insert(31);
	s.insert(31);
	// set �ݺ��ڸ� ++ �ϸ� inorder ���(��������)�� ��ȸ
	show(s);
}