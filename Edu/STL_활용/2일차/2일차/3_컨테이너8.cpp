#include "show.h"
#include <fstream> // ���������

// �����̳ʸ� ��� �����̳ʰ� �������� �����ϴ�.

bool foo(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	ifstream fin("3_�����̳�8.cpp"); // ���� �ҽ��̸� ��������.

	string s;

	vector<string> v;
	while (getline(fin, s))// fin ���� ���� ������
		v.push_back(s);

	//---------------------------------------
	//reverse( v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		//reverse(v[i].begin(), v[i].end());
		//replace(v[i].begin(), v[i].end(), 'i', ' ');

		// ��� ������ ��������
		replace_if(v[i].begin(), v[i].end(), foo, ' ');
	}
	//---------------------------------------

	for (int i = 0; i < v.size();i++)
		cout << v[i] << endl;
}