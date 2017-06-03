#include <binder/IServiceManager.h>
#include <utils/StrongPointer.h>
#include <binder/MemoryHeapBase.h>
#include <binder/IPCThreadState.h>

using namespace android;

int main()
{
	char *p;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IMemoryHeap> heap = new MemoryHeapBase(4096);
	p = (char*)heap->getBase();
	sprintf(p , "Hello Android MemoryHeapBase\n");
	sm->addService(String16("ashmem.service"), heap->asBinder() );
	IPCThreadState::self()->joinThreadPool();
	return 0;
}
