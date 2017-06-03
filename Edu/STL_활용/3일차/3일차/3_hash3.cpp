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

int main()
{
	set<People> s1;
	s1.insert(People("kim", 10));	// ?? 되게 하려면 ? set 은 항상 크기를 비교하며 들어간다.
									// 방법 1. People에 < 연산자가 있으면 된다.
									//		2. set<People, PeopleCompare> 등으로
									//		   People 을 비교하는 비교 함수 객체가 있으면 된다.
									// 둘다 지원하면 당연히 비교함수객체 먼저 사용. less 가 기본 비교함수객체로 쓰기 때문에 < 연산자를 쓰는거니께
}