// 4_initializer_list- 32 page
#include <iostream>
using namespace std;
/*
void foo(initializer_list<int> e)
{
	// ��������� STL�� �����ϰ� ����ϸ� �˴ϴ�.
	// �ݺ��� : ��Ҹ� ����Ű�� �����Ͷ�� �����ϸ� �˴ϴ�.
	initializer_list<int>::iterator p = e.begin();

	while (p != e.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/

/*
void foo(initializer_list<int> e)
{
	auto p = e.begin();

	while (p != e.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/

void foo(initializer_list<int> e)
{
	// ranged for
	for (auto n : e)
		cout << n << endl;
}


int main()
{
	// ���� Ÿ�Կ� ���� �迭�� ������ ���� ��ü.
	initializer_list<int> e = { 1,2,3,4 };
	foo(e);
	
//	foo({ 1,2,3,4,5 }); // C++98������ �Ұ����ߴ� C++11�� ���ο� ǥ��
}






