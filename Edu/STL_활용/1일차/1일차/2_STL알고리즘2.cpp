// 2_STL�˰���1.cpp - ���� 2 page
#include <iostream>
using namespace std;

// �Ϲ�ȭ (Generic) ���α׷��� : �ϳ��� �Լ�(Ŭ����)�� �ִ��� Ȱ�� ������
//								������ �����ڴ� ����..



// 2�ܰ�. �˻� ������ �Ϲ�ȭ - �κ� ���ڿ� �˻��� �����ϰ� ����.

char* xstrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefghijk";

	char* p = xstrchr(s, s+5, 'c');

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}