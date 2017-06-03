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

	friend struct PeopleAgeCompare;
};

// People의 크기를 비교하는 함수 객체
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

	//sort(v.begin(), v.end()); // 주소를 비교하게 된다. 버그...
	sort(v.begin(), v.end(), PeopleAgeCompare()); // 얘로는 * 타입을 받도록 수정
}