//5_������2
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
	lock_guard<mutex> lg(m);		//lock_guard �����ڿ��� m.lock() �մϴ�.
									// �ȵ���̵� Framework ������ Autolock Ŭ����
	x = 100;

}

int main()
{
	thread t1(&foo);
	thread t2(&foo);

	t1.join();
	t2.join();
}