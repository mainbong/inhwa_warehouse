// 5_STL ����ϱ�
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm> // find() ���� �Լ��� �� ����� �ֽ��ϴ�.
using namespace std; // ���� "�˰���" �̶�� �մϴ�.

int main()
{
	string s = "hello world";

	string::iterator p1 = s.begin();
	++p1;
	cout << *p1 << endl; // 'e'

	typedef list<int> Cont;

	Cont s1 = { 1,2,3,4,5,6,7,8,9,10 }; // C++11 �ֽ� ����.

	// s1 �ݺ��� ������ ���� ����� ������
	Cont::iterator s1_iter = s1.begin();
	while (s1_iter != s1.end())
	{
		cout << *s1_iter << endl;
		++s1_iter;
	}
	

	// s1 ������ ������. ������ �˰����� reverse() �Դϴ�.
	//s1.reverse();
	reverse(s1.begin(), s1.end());
	
	// s1 �ٽ� ����غ�����..
	s1_iter = s1.begin();
	while (s1_iter != s1.end())
	{
		cout << *s1_iter << endl;
		++s1_iter;
	}
}
