#include <binder/IServiceManager.h>
#include <utils/StrongPointer.h>
#include <binder/MemoryHeapBase.h>
#include <binder/IPCThreadState.h>
#include <binder/MemoryBase.h>

using namespace android;

int main()
{
	char *p;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IMemoryHeap> heap = new MemoryHeapBase(1024*1024);
	sp<IMemory> memory   = new MemoryBase( heap, 32*1024*2, 32*1024);
	p = (char*)heap->getBase();
	sprintf(p+32*1024*2 , "Hello Android MemoryHeapBase\n");
	sm->addService(String16("ashmem.service"), memory->asBinder() );
	IPCThreadState::self()->joinThreadPool();
	return 0;
}
