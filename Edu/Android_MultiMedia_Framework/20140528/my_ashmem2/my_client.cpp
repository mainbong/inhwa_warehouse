#include <binder/IServiceManager.h>
#include <utils/StrongPointer.h>
#include <binder/MemoryHeapBase.h>
#include <binder/IPCThreadState.h>

using namespace android;

int main()
{
	char *p;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("ashmem.service"));
	sp<IMemoryHeap> heap = interface_cast<IMemoryHeap>( binder );
	p = (char*)heap->getBase();
	printf("p=%s\n", p );
	return 0;
}
