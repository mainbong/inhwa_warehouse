// move4�� ������ ������
// 5_move - C++11�� ���� �߿��� �ٽ�..!- 82 page

// VC++�� strcpy�� ���ȿ� ����ϴٰ� ���� ���� ������ ��찡 �ֽ��ϴ�.
// �Ʒ� ������  ������ ���� ���� ��������..
#define _CRT_SECURE_NO_WARNINGS
#include "logTime.h" // ������ ������

#include <algorithm>
#include <iostream>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	~Cat() { delete[] name; }

	Cat(const Cat& c)
	{
		age = c.age;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		delete[] name;
		age = c.age;
		name = new char[strlen(name) + 1];
		strcpy(name, c.name);

		return *this;
	}
	Cat(Cat&& c)
	{
		name = c.name;
		age = c.age;
		c.name = 0;
		c.age = 0;
	}
	Cat& operator=(Cat&& c) // const�� ����� �մϴ�. ���� �ڿ��� 0���� �Ϸ���
	{
		if (&c == this) return *this;

		delete[] name;

		age = c.age;
		name = c.name;

		c.name = 0;
		c.age = 0;

		return *this;
	}
};

class Cat_No_Move
{
	char* name;
	int   age;
public:
	Cat_No_Move(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	~Cat_No_Move() { delete[] name; }

	Cat_No_Move(const Cat_No_Move& c)
	{
		age = c.age;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	Cat_No_Move& operator=(const Cat_No_Move& c)
	{
		if (&c == this) return *this;
		delete[] name;
		age = c.age;
		name = new char[strlen(name) + 1];
		strcpy(name, c.name);
		return *this;
	}
};


void test1(int cnt)
{
	Cat c1("AAA", 2);
	Cat c2("B",  10);

	for (int i = 0; i < cnt; i++)
		swap(c1, c2); // C++ ǥ�� swap 
}
void test2(int cnt)
{
	Cat_No_Move c1("AAA", 2);
	Cat_No_Move c2("BBB", 10);

	for (int i = 0; i < cnt; i++)
		swap(c1, c2); // C++ ǥ�� swap
}

int main()
{	
	logTime(test1, 1'000'00);
	logTime(test2, 1'000'00);

}

// g++ �ҽ��̸�.cpp  --std=c++1y   �� �ؾ� �մϴ�.






