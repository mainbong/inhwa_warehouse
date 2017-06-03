#include <binder/ProcessState.h>  // libbinder.so
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/Binder.h>
#include <utils/StrongPointer.h>  // libutils.so
#include "ILedService.h"
#include "LedClient.h"

using namespace android;

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService( String16("led.service") );
	sp<ILedService> led = interface_cast<ILedService>( binder );

	sp<ILedClient> ledClient = new LedClient;
	led->connect(ledClient);
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
