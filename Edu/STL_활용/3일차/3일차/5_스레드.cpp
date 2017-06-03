//5_스레드
#include "show.h"
#include <chrono>
using namespace chrono;

// C++11 부터 STL 에서 스레드를 지원합니다.
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
	//thread t(bind(&foo,1,3.4)); // 스레드 생성..
	//thread t(&foo, 1, 3.4);
	FOO f;
	//thread t(f);
	thread t(bind(&FOO::goo, &f)); // 멤버 함수. f.goo()

	t.join();
} 