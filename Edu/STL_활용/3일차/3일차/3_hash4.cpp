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
// ����� ���� Ÿ���� ��������
// 1. �ؽ� �Լ� ( �Լ���ü�� �������Ѵ�. )
// 2. ��� �� �Լ� ��ü�� �־�� �Ѵ�.

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
	s1.insert(People("kim", 10));	// ?? �ǰ� �Ϸ��� ?
	s1.insert(People("robert", 10));
	s1.insert(People("park", 10));
}