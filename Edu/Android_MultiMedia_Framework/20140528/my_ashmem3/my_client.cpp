#include <binder/IServiceManager.h>
#include <utils/StrongPointer.h>
#include <binder/MemoryHeapBase.h>
#include <binder/IPCThreadState.h>
#include <binder/MemoryBase.h>

using namespace android;

int main()
{
	char *p;
	ssize_t offset;
	size_t size;
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("ashmem.service"));
	sp<IMemory> memory = interface_cast<IMemory>( binder );
	sp<IMemoryHeap> heap= memory->getMemory( &offset, &size );
	printf("offset=%d, size=%d\n", offset, size );
	p = (char*)heap->getBase();
	printf("p=%s\n", p+offset );
	return 0;
}
