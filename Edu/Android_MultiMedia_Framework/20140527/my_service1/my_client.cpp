#include <binder/ProcessState.h>  // libbinder.so
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/Binder.h>
#include <utils/StrongPointer.h>  // libutils.so

using namespace android;

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService( String16("led.service") );
	Parcel data, reply;
	binder->transact( 1, data, &reply );

	return 0;
}
