//5_������
#include "show.h"
#include <chrono>
using namespace chrono;

// C++11 ���� STL ���� �����带 �����մϴ�.
#include <thread>


struct FOO
{
	void operator()() { cout << "FOO" << endl; }
	void goo() { cout << "goo" << endl; }
};

void foo(int a, double d)
{
	cout << "foo : " << a << " "<< d<< endl;
	this_thread::sleep_for(1min);
}

int main()
{
	//thread t(bind(&foo,1,3.4)); // ������ ����..
	//thread t(&foo, 1, 3.4);
	FOO f;
	//thread t(f);
	thread t(bind(&FOO::goo, &f)); // ��� �Լ�. f.goo()

	t.join();
} 