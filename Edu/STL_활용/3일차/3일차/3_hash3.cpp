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
	s1.insert(People("kim", 10));	// ?? �ǰ� �Ϸ��� ? set �� �׻� ũ�⸦ ���ϸ� ����.
									// ��� 1. People�� < �����ڰ� ������ �ȴ�.
									//		2. set<People, PeopleCompare> ������
									//		   People �� ���ϴ� �� �Լ� ��ü�� ������ �ȴ�.
									// �Ѵ� �����ϸ� �翬�� ���Լ���ü ���� ���. less �� �⺻ ���Լ���ü�� ���� ������ < �����ڸ� ���°Ŵϲ�
}