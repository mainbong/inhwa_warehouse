// 8_override- 73 page.. 간단한 문법

class Base
{
public:
	virtual void foo(int a) {}
	virtual void goo() const {}
	void hoo() {}
};
/*
class Derived : public Base
{
public:
	// 다음중 개발자의 실수를 모두 고르세요
	virtual void foo() {}		// 1. 실수 인자가 없다
	void foo(int a) {}			// 2. ok..
	virtual void foo(double d) {} // 3. 실수. 인자 타입이 다르다
	virtual void goo() {}		  // 4. 실수, 상수 함수이어야 한다.
	virtual void gooo() const {}	 // 5. 실수 함수이름이 틀렸다
	void hoo() {}					// 6. 문법적으로 되지만 가상함수가 아닌함수를
									//    재정의 하는 것은 좋지 않다.
};
*/

class Derived : public Base
{
public:
	// 다음중 개발자의 실수를 모두 고르세요
	//virtual void foo() override {}		// 1. 실수 인자가 없다

	// final 가상함수 : 더이상 자식이 재정의 할수 없게 한다.
	void foo(int a) override final {}			// 2. ok..
	//virtual void foo(double d)override {} // 3. 실수. 인자 타입이 다르다
//	virtual void goo() override {}		  // 4. 실수, 상수 함수이어야 한다.
//	virtual void gooo()  const override{}	 // 5. 실수 함수이름이 틀렸다
//	void hoo() override {}					// 6. 문법적으로 되지만 가상함수가 아닌함수를
									//    재정의 하는 것은 좋지 않다.
};
int main()
{
}





