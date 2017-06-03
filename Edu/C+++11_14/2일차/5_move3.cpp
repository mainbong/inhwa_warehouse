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
	// Rule Of 3 : �����ڿ��� �ڿ��Ҵ��� �ϸ� 
	//				3���� �Լ��� �߰��� �����ؾ� �մϴ�.
	//				�Ҹ���, ���� ������, ���Կ�����

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
	// ������ Cat c2 = c1�� ��� ���� �����ڸ� ȣ���ϰ� �ؾ� �Ѵ�.
	// ���ο� Move �����ڴ� Cat&& �� ���ڷ� �������� ����ߴ�
	Cat( Cat&& c)
	{
		name = c.name;
		age = c.age;
		c.name = 0;
		c.age = 0;
	}
};

// rvalue�� ĳ�����ϴ� �Լ�
template<typename T> T&& move(T& a)
{
	return static_cast<T&&>(a);
}

template<typename T> void Swap(T& a, T& b)
{
//	T tmp = a; // ���� ������ ȣ��.. -��������
//	a = b; 
//	b = tmp;

//	T tmp = static_cast<T&&>(a); // Move ������ ȣ�� - ����������
//	a = static_cast<T&&>(b);
//	b = static_cast<T&&>(tmp);

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







