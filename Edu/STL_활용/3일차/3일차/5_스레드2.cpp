//5_스레드2
#include "show.h"
#include <thread>
#include <mutex>

mutex m;

long x = 10;

/*
void foo()
{
	m.lock();
	x = 100;
	m.unlock();
	cout << x << endl;
}
*/
void foo()
{
	lock_guard<mutex> lg(m);		//lock_guard 생성자에서 m.lock() 합니다.
									// 안드로이드 Framework 에서는 Autolock 클래스
	x = 100;

}

int main()
{
	thread t1(&foo);
	thread t2(&foo);

	t1.join();
	t2.join();
}