#include <iostream>
using namespace std;
// 69 page �Ʒ� �κ�.. ��� data ĸ��
class Test
{
	int data;
public:
	void foo()
	{
		//auto f1 = [data]() { cout << data << endl; }; // error
		int data = 100;
		// ��� data�� �Ʒ� ó�� ĸ�� �ϸ� ���� �����Ҽ��� �ֽ��ϴ�.
		//auto f1 = [this]() { data = 30; cout << data << endl; };
		auto f1 = [=]() { this->data = 30; cout << data << endl; };

		f1(); // ȣ���ؾ� ���ٰ� ����˴ϴ�.

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

	// ���ڰ� �������� ()�� �����ص� �˴ϴ�. - Nullary Lambda - 70 page
	auto f4 = [] { cout << "aaa" << endl; }; f4();
	*/
}









