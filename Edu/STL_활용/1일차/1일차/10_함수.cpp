// 10_�Լ�
#include "show.h"

// �˰��� ���ڷ� �Լ��� ���޵Ǵ� ��찡 �����ϴ�.
// ���� �Լ� : ���ڰ� �Ѱ��� ��
// ���� �Լ� : ���ڰ� 2���� ��


bool foo(int a) { return a % 4 == 0; }

int main()
{
	list<int> s = { 1,2,3,8,7,6 };

	// 1. s ���� ó�� ������ 3�� ã�ƺ�����.
	list<int>::iterator p1 = find(s.begin(), s.end(), 3); // ��� �˻�
	cout << *p1 << endl; // 3
	
	// 2. s ���� ó�� ������ 4�� ����� ã�ƺ�����.
	list<int>::iterator p2 = find_if(s.begin(), s.end(), foo); // ���� �˻�
	cout << *p2 << endl; // 8
}