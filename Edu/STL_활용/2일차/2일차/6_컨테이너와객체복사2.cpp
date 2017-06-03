#define _CRT_SECURE_NO_WARNINGS
// 6_�����̳ʿͰ�ü����
#include "show.h"

class People
{
	char* name;
public:
	People(const char* n = "AA")
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~People() { delete[] name; }

	People(const People& p)
	{
		cout << "���� ������ ȣ��" << endl;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
	
	// C++11�� Move ������ - ������ ������ ����� ���
	// move ������ ���鶧�� ���ܰ� ���ٰ� ǥ���ϴ� ���� �����ϴ�.
	// move �� ���ܰ� �߻��ϸ� ���º����� �ȵǱ� ������, ���ܰ� ������ ��������� ��� �����ϴ�.
	People(People&& p) noexcept
	{
		cout << "move ������ ȣ��" << endl;

		name = p.name;	// ���� ���� ��
		p.name = 0;		// ������ 0����
	}
	
};

int main()
{	
	//People p1("AA");
	//People p2 = p1; // ���� ������
	//People p3 = move(p1); // move������ ȣ��. ������ ���� ������ ȣ��.

	vector<People> v(10);
	v.resize(20); // �̼����� �����غ�����.
	// �̼��� ���� AAA���õ��� ���������� 20���� �޸𸮿� ���� ���簡 �Ͼ.
	// �׸��� ���� AAA���õ��� ��� ���ŵǴµ�, �̴� �ſ� ��ȿ����. ���Ž�ų���̶�� ���� ����� �����͸� ���°� ���� �ʰڳ�.
}