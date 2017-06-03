#include <iostream>
using namespace std;

template<typename T> class Base
{
public:
	// T가 상수라는 표현
	// T 가 int* 를 넣으면 결국 포인터가 상수라는것.
	//virtual void foo(const T& p) { cout << "Base foo" << endl; }
	 
	virtual void foo( T const& p) { cout << "Base foo" << endl; }
};

class Derived : public Base<int*>
{
public:
	// 아래 표현은 상수를 가르키는 포인터의 참조
	//virtual void foo(const int*& p) override { cout << "Derived foo" << endl; }

	//아래가 맞는 재정의 표현입니다.
	virtual void foo(int* const& p) override { cout << "Derived foo" << endl; }
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // 자식 함수가 호출되야 합니다
}





