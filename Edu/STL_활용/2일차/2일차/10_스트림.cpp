// 10_��Ʈ��

#include <iostream>	// ǥ�� �����
#include <fstream>	// ���� �����
#include <sstream>	// �޸�(string) �����
#include <string>
using namespace std;

int main()
{
	int n = 10;

	cout << "n = " << n << endl;
	ostringstream oss;

	oss << "n = " << n;
	cout << oss.str() << endl;
}

/*
int main()
{
	string s;
	//cin >> s;

	//ifstream fin("10_��Ʈ��.cpp");
	//fin >> s; // ���Ͽ��� �Է�

	istringstream iss("i am a boy");	
	// String Tokenizing ó�� ����
	while( iss >> s )
		cout << s << endl;
}*/