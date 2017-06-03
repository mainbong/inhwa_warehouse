// 5_move - C++11의 가장 중요한 핵심..!- 82 page
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
	// Rule Of 5 : 생성자에서 자원할당을 하면 
	//				5개의 함수를 추가로 제공해야 합니다.
	//				소멸자, 복사 생성자, 대입연산자, Move 생성자, Move 대입연산자

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

	// Move 생성자 - 소유권 이전의 기법으로 만든다.
	Cat(Cat&& c)
	{
		name = c.name;
		age = c.age;
		c.name = 0;
		c.age = 0;
	}

	//Move 대입 연산자
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

template<typename T> void Swap(T& a, T& b)
{
	T tmp = move(a);
	a = move(b);
	b = move(tmp);
}


int main()
{
	Cat c1("AAA", 2);
	Cat c2("BBB", 3);
	Swap(c1, c2);
}







