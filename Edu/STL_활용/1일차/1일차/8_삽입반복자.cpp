// 8_���Թݺ���
#include "show.h"

// Ŭ�������ø��� �Ͻ��� �߷��� ���� �����Ƿ� ���� ������ ���δ�.

// �Ͻ��� �߷��� ������ �Լ� ���ø��� ����ؼ� Ŭ���� ���ø��� �����Ѵ�.
/*
template<typename T>
back_insert_iterator<T> back_inserter(T& c)
{
	return back_insert_iterator<T>(c);
}
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };

	list<int> s(5, 0); // 5���� 0����
	//copy(x, x + 5, s.begin()); // ���� s �� �����...

	// s �� ���� �߰��ϴ� ��� 3����
	// 1.push_back() ���
	for (int i = 0; i < 5; i++)
		s.push_back(x[i]);	

	// 2. �Ĺ���� �ݺ��� ���
	//back_insert_iterator<list<int>> p(s); // p�� s�� ���� �߰��ϴ� �ݺ���

	//*p = 30; // s.push_back(30);

	//copy(x, x + 5, p);

	// 3. �Ĺ���� �ݺ��ڸ� ����� �Լ� ���
	copy(x, x + 5, back_inserter(s));

	show(s);
}

/*
template<typename T> T square(T a) { return a * a; }

// ������ ������� ?
square(3);		// 1 . �����Ϸ��� T ����. �Ͻ��� �߷�
square<int>(3);	// 2 . ����ڰ� T ����. ����� �߷�
/


list<int> s(5, 3); // ?
*/