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
/*
template<typename T> class hash {}; // primary template

template<> class hash<int>
{
	inline size_t operator()(int a) {}
};
template<> class hash<string>
{
	inline size_t operator()(string a) {}
};
//.. ǥ��Ÿ���� ��ó�� �� ������� �������̴�.
*/
// �� PeopleHash ���� �̸��� �ʿ� ���� �ϱ�� ���� ����� ����ϰ� �־��� �ʿ䰡 ���� �ڵ����� ã�ư���.
// C++ ǥ���� hash primary template�� People �������� ����ȭ(specialization) �մϴ�.
template<> class hash<People>
{
public:
	inline size_t operator()(const People& p) const
	{
		return hash<string>()(p.name) + hash<int>()(p.age);
	}
};

template<> class equal_to<People>
{
public:
	inline bool operator()(const People& p1, const People& p2) const
	{
		return p1.name == p2.name && p1.age == p2.age;
	}
};

int main()
{
	unordered_set<People> s1;
	s1.insert(People("kim", 10));	// ?? �ǰ� �Ϸ��� ?
	s1.insert(People("robert", 10));
	s1.insert(People("park", 10));
}

/*
template<typename T> class stack {};
template<typename T> class stack<T*> {};
template<typename T> class stack<int> {};

stack<double> s1;
stack<int*> s2;*/