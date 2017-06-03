// 14_thread
#include <iostream>
#include <functional>
using namespace std;

// C++11�� ��Ƽ�����带 ���� ���̺귯���� �����մϴ�.
#include <thread>

void foo(int a, double d)
{
	cout << "foo" << endl;
}

struct FOO
{
public:
	void operator()(int a) { cout << "FOO" << endl; }

	void goo() { cout << "goo" << endl; }
};

int main()
{
	//thread t(foo, 1, 3.4); // �̼��� �����尡 �����Ǿ ����˴ϴ�.
	//thread t(FOO(), 1); // �Լ���ü�� ��밡��.

	FOO f;
    thread t( &FOO::goo, FOO() ); // ��� �Լ��� ����.

	t.join(); // ������ ���Ḧ ����Ѵ�.
}
