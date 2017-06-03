#include "show.h"
#include <memory>
#include <windows.h>

// cafe.naver.com/cppmaster ���������ڷ�ǿ��� "ŰĹ" �˻��ؼ� �޾ƺ�����.
// ���� Ǯ�����.

// ��Ƽ�����带 Ŭ������ ����� ���ô�.
class Thread
{
	shared_ptr<Thread> mHoldSelf; // �ڽ��� ��������� �����ϱ� ����
public:
	//Thread() : mHoldSelf(this) {} // �����ڿ��� �ص� �ɱ�� ?
									// ��� ���� �ȵ���. �����带 ���� �������� �ؾ� �մϴ�.

	void run(shared_ptr<Thread> sp) 
	{ 
		//mHoldSelf = this; //�̷��� �ص� �ɱ�� ? �ȵ��� �̰� �������ǥ�� ���Ӱ� �ϳ� �� �����. �ϴ� ���� ����
		mHoldSelf = sp;
		CreateThread(0, 0, foo, this, 0, 0); 
	}
	static DWORD __stdcall foo(void* p)
	{
		Thread* self = (Thread*)p;
		self->threadMain();

		// thread �� ������ ���� ��������� �ٿ������.
		// �ȱ׷��� �� shared_ptr �� ������ �ı����� ����.
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
		// ���ڸ� �ȳѱ�� �ϴ� ����� ������!? ���ڽ��� ����!
		sp->run(sp);
	}
	// Thread �� ���� ���ε� shared_ptr�� ���� Thread ��ü�� �ı��ȴ�. ���α׷��� �װԵ�. ������

	while (1);
}

shared_ptr<int> p1(new int);
shared_ptr<int> p2 = p1;

int* p = new int;
shared_ptr<int> p3(p); // ������� 1
shared_ptr<int> p4(p); // �̷� ��쿣 ��¥ �����ͱ� ������ ��������� ���� ������ ����. �Ǵٽ� 1...