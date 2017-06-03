//3_�����̳�4
#include "show.h"

// ����� ���� Ÿ�԰� STL �����̳�.
// 1. ����Ʈ �����ڰ� �ִ� ���� ����. ���� ��� main()����.

class People
{
	string name;
	int age;
public:
	People(string n, int a) : name(n), age(a) {}
};

int main()
{
	vector<People> v(10, People("unknown", 0));
	v.resize(20, People("unknown", 0)); // resize(20) �غ�����

	// 2. ��� �ֱ�
	People p1("park", 20);
	v.push_back(p1); // �̰��� �� ����� ���������� p1 �� �޸𸮿� ����, ������.

	// �ӽ� ��ü�� ����ؼ� �ֱ�.
	v.push_back(People("kim", 10));

	// ������ ���ڸ� �����ؼ� People ��ü�� vector �� ����� ����.
	v.emplace_back("lee", 30); // C++11 �� ���� ���� �Լ�.
}