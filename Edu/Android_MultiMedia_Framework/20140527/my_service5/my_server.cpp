#include <binder/ProcessState.h>  // libbinder.so
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/Binder.h>
#include <utils/StrongPointer.h>  // libutils.so
#include "LedService.h"

using namespace android;

int main()
{
	LedService::instantiate();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
