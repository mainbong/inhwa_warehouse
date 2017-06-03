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

};

template<typename T> void Swap(T& a, T& b)
{
	T tmp = move(a); // 1. move 생성자가 있다면 move 생성자 사용
					 // 2. move 생성자가 없다면 복사생성자 사용

					// rvalue => Cat&&, 없다면 const Cat& 사용
	a = move(b);
	b = move(tmp);
}


int main()
{
	Cat c1("AAA", 2);
	Cat c2("BBB", 3);
	Swap(c1, c2);
}







