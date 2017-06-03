#include "show.h"
#include <memory>
#include <windows.h>

// cafe.naver.com/cppmaster 예전수업자료실에서 "키캣" 검색해서 받아보세요.
// 압축 풀어보세요.

// 멀티스레드를 클래스로 만들어 봅시다.
class Thread
{
	shared_ptr<Thread> mHoldSelf; // 자신의 참조계수를 증가하기 위해
public:
	//Thread() : mHoldSelf(this) {} // 생성자에서 해도 될까요 ?
									// 노우 절대 안되죠. 스레드를 만든 시점에서 해야 합니다.

	void run(shared_ptr<Thread> sp) 
	{ 
		//mHoldSelf = this; //이렇게 해도 될까요 ? 안되죠 이건 참조계수표를 새롭게 하나 더 만들뿐. 하단 예제 참조
		mHoldSelf = sp;
		CreateThread(0, 0, foo, this, 0, 0); 
	}
	static DWORD __stdcall foo(void* p)
	{
		Thread* self = (Thread*)p;
		self->threadMain();

		// thread 가 끝나기 전에 참조계수를 줄여줘야함.
		// 안그러면 이 shared_ptr 은 영원히 파괴되지 않음.
		self->mHoldSelf.reset();
		return 0;
	}
	virtual void threadMain() {};
};

class MyThread :public Thread
{
	int data;
public:
	virtual void threadMain() { cout << "mythread" << endl; }
};

int main()
{
	{
		shared_ptr<MyThread> sp(new MyThread);
		// 인자를 안넘기고 하는 방법이 없을까!? 담코스를 보자!
		sp->run(sp);
	}
	// Thread 는 도는 중인데 shared_ptr에 의해 Thread 객체가 파괴된다. 프로그램이 죽게됨. ㄷㄷㄷ

	while (1);
}

shared_ptr<int> p1(new int);
shared_ptr<int> p2 = p1;

int* p = new int;
shared_ptr<int> p3(p); // 참조계수 1
shared_ptr<int> p4(p); // 이럴 경우엔 진짜 포인터기 때문에 참조계수에 대한 정보가 없어. 또다시 1...