// 3_hash
#include "show.h"
#include <set> // RB Tree
#include <unordered_set> // hash

struct People
{
	string name;
	int age;

	People(string n = "", int a = 0) : name(n), age(a) {}


};
// 사용자 정의 타입을 넣으려면
// 1. 해쉬 함수 ( 함수객체로 만들어야한다. )
// 2. 상등 비교 함수 객체가 있어야 한다.

struct PeopleHash
{
	inline size_t operator()(const People& p) const
	{
		return hash<string>()(p.name) + hash<int>()(p.age);
	}
};

struct PeopleEqual
{
	inline bool operator()(const People& p1, const People& p2) const
	{
		return p1.name == p2.name && p1.age == p2.age;
	}
};

int main()
{
	unordered_set<People, PeopleHash, PeopleEqual> s1;
	s1.insert(People("kim", 10));	// ?? 되게 하려면 ?
	s1.insert(People("robert", 10));
	s1.insert(People("park", 10));
}