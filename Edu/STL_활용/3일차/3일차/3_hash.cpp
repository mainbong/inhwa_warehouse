// 3_hash
#include "show.h"
#include <set> // RB Tree
#include <unordered_set> // hash

int main()
{
	hash<int> hi; // �ؽ� �Լ�( �Լ� ��ü�� �Ǿ� �ֽ��ϴ�. )

	cout << hi(10) << endl;
	cout << hi(20) << endl;
	cout << hi(10) << endl;
	
	// ���ڿ��� �ؽ� �Լ��� ����� ������
	hash<string> hs;
	cout << hs("hello") << endl;
	cout << hs("abcd") << endl;

	cout << hash<double>()(3.4) << endl; // �̷�ǥ���� �˾��ּ���
}