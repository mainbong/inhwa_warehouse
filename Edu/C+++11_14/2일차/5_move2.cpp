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
	// Rule Of 3 : 생성자에서 자원할당을 하면 
	//				3개의 함수를 추가로 제공해야 합니다.
	//				소멸자, 복사 생성자, 대입연산자

	~Cat() { delete[] name; }



	// 소유권 이전의 복사 생성자 - 84 page 그림
	Cat( Cat& c) // 주의 const가 없습ㄴ다.
	{
		// 얕은 복사
		age = c.age;
		name = c.name;

		c.name = 0;
		c.age = 0;
	}








	// 얕은 복사 현상이 있는 경우는 대입연산자도 필요하다.
	Cat& operator=(const Cat& c)
	{
		// 0. 항상 자신과의 대입을 확인해야 한다.
		if (&c == this) return *this;

		// 1. 기존 버퍼를 지우고
		delete[] name;
		// 2. 복사생성자와 동일하게 구현
		age = c.age;
		name = new char[strlen(name) + 1];
		strcpy(name, c.name);

		// 3. 자기 자신을 참조로 리턴
		return *this;
	}
};


int main()
{
	Cat c1("AAA", 2);
	Cat c2 = c1; 
}
