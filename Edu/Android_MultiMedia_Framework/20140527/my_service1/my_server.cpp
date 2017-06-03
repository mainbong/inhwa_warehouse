#include <binder/ProcessState.h>  // libbinder.so
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/Binder.h>
#include <utils/StrongPointer.h>  // libutils.so

using namespace android;

class AAA : public BBinder
{
	public : 
		status_t onTransact(
				uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
		{
			switch (code) {
				case 1:
					printf("AAA::LED_ON\n");
					return NO_ERROR;

				default:
				   return BBinder::onTransact(code, data, reply, flags);
			}
		}
};

int main()
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	sm->addService( String16("led.service"), new AAA );
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
