// 5_STL ����ϱ�
/*
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm> // find() ���� �Լ��� �� ����� �ֽ��ϴ�.
using namespace std; // ���� "�˰���" �̶�� �մϴ�.

// ��� �����̳��� ��Ҹ� ����ϴ� �Լ�
template<typename T> void show(T& c)
{
	typename T::iterator p = c.begin();
	while (p != c.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/
#include "show.h"

int main()
{	
	typedef list<int> Cont;

	Cont s1 = { 1,2,3,4,5,6,7,8,9,10 };
	show(s1);
}