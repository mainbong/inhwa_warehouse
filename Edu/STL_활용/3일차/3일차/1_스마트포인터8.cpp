#include "show.h"
#include <memory>
#include <windows.h>


// 외부에서 shared_ptr<>로 객체를 관리할 때...
// 객체 스스로가 자신의 참조계수를 증가하고 싶다면... enable_shared_from_this 를 상속받자
class Thread : public enable_shared_from_this<Thread>
{
	shared_ptr<Thread> mHoldSelf;
public:
	void run()
	{		
		mHoldSelf = shared_from_this(); // 외부에서 만든 shared_ptr<> 이
										// 사용하는 관리 객체를 공유하게 한다.
		CreateThread(0, 0, foo, this, 0, 0);
	}
	static DWORD __stdcall foo(void* p)
	{	
		// mHoldSelf 를 지역변수에 옮겨 담습니다. 이것이 가장 안전하게 블록이 끝났을 때 레퍼런스를 제거해줄 수 있기 때문입니다.
		Thread* self = (Thread*)p;
		shared_ptr<Thread> me(self->mHoldSelf);
		self->mHoldSelf.reset();

		self->threadMain();
		//self->mHoldSelf.reset();
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
		sp->run();
	}
	// Thread 는 도는 중인데 shared_ptr에 의해 Thread 객체가 파괴된다. 프로그램이 죽게됨. ㄷㄷㄷ

	while (1);
}
