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

	friend struct PeopleAgeCompare;
};

// People�� ũ�⸦ ���ϴ� �Լ� ��ü
struct PeopleAgeCompare
{
	int order;
	PeopleAgeCompare(int or = 0) : order(or ) {}
	inline bool operator()(const People* p1, const People* p2)
	{
		if (order == 1)
			return p1->age > p2->age;
		return p1->age < p2->age;
	}
};

int main()
{
	vector<People*> v;

	v.push_back(new People("aaa", 10));
	v.push_back(new People("bbb", 20));
	v.push_back(new People("ccc", 15));

	//sort(v.begin(), v.end()); // �ּҸ� ���ϰ� �ȴ�. ����...
	sort(v.begin(), v.end(), PeopleAgeCompare()); // ��δ� * Ÿ���� �޵��� ����
}