// 14_thread2
#include <thread>
#include <mutex>
using namespace std;

mutex t;
int x = 100;

void foo()
{
	lock_guard<mutex> lg(t); // 생성자에서 t.lock(), 소멸자에서 t.unlock()

//	t.lock();
	x = 200;
//	t.unlock();
}

int main()
{
	thread t(foo);

	t.join();
}






