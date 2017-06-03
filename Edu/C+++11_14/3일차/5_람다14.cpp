#include <iostream>
using namespace std;
// 69 page 아래 부분.. 멤버 data 캡쳐
class Test
{
	int data;
public:
	void foo()
	{
		//auto f1 = [data]() { cout << data << endl; }; // error
		int data = 100;
		// 멤버 data는 아래 처럼 캡쳐 하면 값을 변경할수도 있습니다.
		//auto f1 = [this]() { data = 30; cout << data << endl; };
		auto f1 = [=]() { this->data = 30; cout << data << endl; };

		f1(); // 호출해야 람다가 실행됩니다.

		data = 20;
		cout << data << endl;
	}
};
int main()
{
	Test t;
	t.foo();
	/*
	auto f2 = [](int a) { cout << "aaa" << endl; }; f2(1);
	auto f3 = []()      { cout << "aaa" << endl; }; f3();

	// 인자가 없을때는 ()를 생략해도 됩니다. - Nullary Lambda - 70 page
	auto f4 = [] { cout << "aaa" << endl; }; f4();
	*/
}









