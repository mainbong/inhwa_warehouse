// 6_�ݺ�������
#include "show.h"

int main()
{
	vector<int> v(10, 3); // 10���� 3���� �ʱ�ȭ
	vector<int>::iterator p = v.begin();

	cout << *p << endl;

	//v.resize(20); // �� ���� �̸� ���� ���� �ݺ��ڴ� ��ȿȭ �˴ϴ�.
				  // ����ϸ� �ȵ˴ϴ�.

	v.resize(5); // ?
	
	cout << v.size() << endl; //5
	cout << v.capacity() << endl; // 10

	cout << *p << endl; // ???
}