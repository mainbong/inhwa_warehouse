#include "show.h"
#include <map> // pair�� �����ϴ� set. key������ data ����

int main()
{
	map<string, string> m;

	// ��� �ֱ� 1.
	pair<string, string> p1("mon", "������");
	m.insert(p1);

	m.insert(make_pair("sun", "�Ͽ���"));

	// [] �����ڻ��
	m["wed"] = "������";

	cout << m["wed"] << endl; // ������
	cout << m["fri"] << endl; // "fri"�� ���� ��� ���Ӱ� ����� �˴ϴ�.
								// ��, m.insert(make_pair("fri"), "")

	// Ű���� �ִ��� �����Ϸ���
	map<string, string>::iterator p = m.find("wed");

	if (p == m.end())
		cout << "tue �� �����ϴ�." << endl;
	// p �� ����ؼ� "wed"�� "������"�� ����غ�����.
	// �ݺ��� : ��Ҹ� ����Ű�� ������ ��Ȱ.
	else
		cout << p->first << "�� " << p->second << endl;
	
}