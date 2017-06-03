//3_�����̳�5
#include "show.h"

using namespace std::rel_ops; // relational operators �� ����

// ����
/*
namespace std
{
	namespace rel_ops
	{
		template<typename T> bool operator>(const T& a, const T& b)
		{
			return !(a < b) && !(a == b);
		}
	}
}
*/

class People
{
	string name;
	int age;
public:
	People(string n, int a) : name(n), age(a) {}
	bool operator<(const People& p) const { return age < p.age; } // ���⼭ const �� ������ Template ���� const T& �� �� �Լ��� ȣ������ ���ؼ� ������.
	bool operator==(const People& p) const { return age == p.age; }

	friend struct PeopleAgeCompare;
};

int main()
{
	People p1("aaa", 10);
	People p2("aaa", 15);

	bool b1 = p1 < p2; // ok...
	bool b2 = p1 > p2; // error... less �� �ְ� gt �� �������� �ʾ���. �׷��� std::rel_ops �� �����ϴ¼��� �����ذ�
}