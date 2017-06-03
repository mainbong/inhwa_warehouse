// move4번 복사해 오세요
// 5_move - C++11의 가장 중요한 핵심..!- 82 page

// VC++은 strcpy가 보안에 취약하다고 가끔 에러 나오는 경우가 있습니다.
// 아래 한줄을  파일의 제일 위에 놓으세요..
#define _CRT_SECURE_NO_WARNINGS
#include "logTime.h" // 복사해 오세요

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
	Cat& operator=(Cat&& c) // const가 없어야 합니다. 원본 자원을 0으로 하려면
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
		swap(c1, c2); // C++ 표준 swap 
}
void test2(int cnt)
{
	Cat_No_Move c1("AAA", 2);
	Cat_No_Move c2("BBB", 10);

	for (int i = 0; i < cnt; i++)
		swap(c1, c2); // C++ 표준 swap
}

int main()
{	
	logTime(test1, 1'000'00);
	logTime(test2, 1'000'00);

}

// g++ 소스이름.cpp  --std=c++1y   로 해야 합니다.






