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



	// ������ ������ ���� ������ - 84 page �׸�
	Cat( Cat& c) // ���� const�� ��������.
	{
		// ���� ����
		age = c.age;
		name = c.name;

		c.name = 0;
		c.age = 0;
	}








	// ���� ���� ������ �ִ� ���� ���Կ����ڵ� �ʿ��ϴ�.
	Cat& operator=(const Cat& c)
	{
		// 0. �׻� �ڽŰ��� ������ Ȯ���ؾ� �Ѵ�.
		if (&c == this) return *this;

		// 1. ���� ���۸� �����
		delete[] name;
		// 2. ��������ڿ� �����ϰ� ����
		age = c.age;
		name = new char[strlen(name) + 1];
		strcpy(name, c.name);

		// 3. �ڱ� �ڽ��� ������ ����
		return *this;
	}
};


int main()
{
	Cat c1("AAA", 2);
	Cat c2 = c1; 
}
