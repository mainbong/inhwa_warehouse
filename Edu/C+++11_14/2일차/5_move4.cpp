// 5_move - C++11�� ���� �߿��� �ٽ�..!- 82 page
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
	// Rule Of 5 : �����ڿ��� �ڿ��Ҵ��� �ϸ� 
	//				5���� �Լ��� �߰��� �����ؾ� �մϴ�.
	//				�Ҹ���, ���� ������, ���Կ�����, Move ������, Move ���Կ�����

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

	// Move ������ - ������ ������ ������� �����.
	Cat(Cat&& c)
	{
		name = c.name;
		age = c.age;
		c.name = 0;
		c.age = 0;
	}

	//Move ���� ������
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







