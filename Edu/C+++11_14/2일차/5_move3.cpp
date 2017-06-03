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
	// 기존의 Cat c2 = c1은 계속 복사 생성자를 호출하게 해야 한다.
	// 새로운 Move 생성자는 Cat&& 를 인자로 가지도록 약속했다
	Cat( Cat&& c)
	{
		name = c.name;
		age = c.age;
		c.name = 0;
		c.age = 0;
	}
};

// rvalue로 캐스팅하는 함수
template<typename T> T&& move(T& a)
{
	return static_cast<T&&>(a);
}

template<typename T> void Swap(T& a, T& b)
{
//	T tmp = a; // 복사 생성자 호출.. -깊은복사
//	a = b; 
//	b = tmp;

//	T tmp = static_cast<T&&>(a); // Move 생성자 호출 - 소유권이전
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







