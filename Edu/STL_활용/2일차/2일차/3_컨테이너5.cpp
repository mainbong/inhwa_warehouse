//3_�����̳�5
#include "show.h"

// ����� ���� Ÿ�԰� STL �����̳�.
// 1. ����Ʈ �����ڰ� �ִ� ���� ����. ���� ��� main()����.

class People
{
	string name;
	int age;
public:
	People(string n, int a) : name(n), age(a) {}

	// vector�� �ֱ����� ũ��� �Լ��� ���� �ʿ� ������
	// sort() ���� ����Ϸ��� �ʿ��ϴ�. ��� �Լ��� ����� ���� �����ϴ�.
	// bool operator<(const People& p) const { return age < p.age; }
	// bool operator==(const People& p) const { return age == p.age; }

	friend struct PeopleAgeCompare;
};

// People�� ũ�⸦ ���ϴ� �Լ� ��ü
struct PeopleAgeCompare
{
	int order;
	PeopleAgeCompare(int or = 0) : order(or ) {}
	inline bool operator()(const People& p1, const People& p2)
	{
		if (order == 1)
			return p1.age > p2.age;
		return p1.age < p2.age;
	}
};

int main()
{
	vector<People> v;

	v.emplace_back("kim", 20);
	v.emplace_back("aaa", 30);
	v.emplace_back("bbb", 10);

	// sort(v.begin(), v.end()); // �⺻������ < �� == ���� ���ϰ� �ִ�.
	sort(v.begin(), v.end(), PeopleAgeCompare());
}