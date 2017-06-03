// 14_thread
#include <iostream>
#include <functional>
using namespace std;

// C++11은 멀티스레드를 공식 라이브러리로 제공합니다.
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
	//thread t(foo, 1, 3.4); // 이순간 스레드가 생성되어서 실행됩니다.
	//thread t(FOO(), 1); // 함수객체도 사용가능.

	FOO f;
    thread t( &FOO::goo, FOO() ); // 멤버 함수도 가능.

	t.join(); // 스레드 종료를 대기한다.
}
