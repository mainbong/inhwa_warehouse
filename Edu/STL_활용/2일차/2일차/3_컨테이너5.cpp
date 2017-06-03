//3_컨테이너5
#include "show.h"

// 사용자 정의 타입과 STL 컨테이너.
// 1. 디폴트 생성자가 있는 것이 좋다. 없는 경우 main()참고.

class People
{
	string name;
	int age;
public:
	People(string n, int a) : name(n), age(a) {}

	// vector에 넣기위해 크기비교 함수가 있을 필요 없지만
	// sort() 등을 사용하려면 필요하다. 상수 함수로 만드는 것이 좋습니다.
	// bool operator<(const People& p) const { return age < p.age; }
	// bool operator==(const People& p) const { return age == p.age; }

	friend struct PeopleAgeCompare;
};

// People의 크기를 비교하는 함수 객체
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

	// sort(v.begin(), v.end()); // 기본적으로 < 와 == 으로 비교하고 있다.
	sort(v.begin(), v.end(), PeopleAgeCompare());
}