#include "show.h"
#include <memory>
#include <windows.h>


// �ܺο��� shared_ptr<>�� ��ü�� ������ ��...
// ��ü �����ΰ� �ڽ��� ��������� �����ϰ� �ʹٸ�... enable_shared_from_this �� ��ӹ���
class Thread : public enable_shared_from_this<Thread>
{
	shared_ptr<Thread> mHoldSelf;
public:
	void run()
	{		
		mHoldSelf = shared_from_this(); // �ܺο��� ���� shared_ptr<> ��
										// ����ϴ� ���� ��ü�� �����ϰ� �Ѵ�.
		CreateThread(0, 0, foo, this, 0, 0);
	}
	static DWORD __stdcall foo(void* p)
	{	
		// mHoldSelf �� ���������� �Ű� ����ϴ�. �̰��� ���� �����ϰ� ����� ������ �� ���۷����� �������� �� �ֱ� �����Դϴ�.
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
		// ���ڸ� �ȳѱ�� �ϴ� ����� ������!? ���ڽ��� ����!
		sp->run();
	}
	// Thread �� ���� ���ε� shared_ptr�� ���� Thread ��ü�� �ı��ȴ�. ���α׷��� �װԵ�. ������

	while (1);
}
