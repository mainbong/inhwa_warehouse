//3_컨테이너5
#include "show.h"

using namespace std::rel_ops; // relational operators 의 약자

// 원리
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
	bool operator<(const People& p) const { return age < p.age; } // 여기서 const 가 빠지면 Template 에서 const T& 가 이 함수를 호출하지 못해서 에러남.
	bool operator==(const People& p) const { return age == p.age; }

	friend struct PeopleAgeCompare;
};

int main()
{
	People p1("aaa", 10);
	People p2("aaa", 15);

	bool b1 = p1 < p2; // ok...
	bool b2 = p1 > p2; // error... less 만 있고 gt 는 정의하지 않았음. 그러나 std::rel_ops 를 정의하는순간 문제해결
}