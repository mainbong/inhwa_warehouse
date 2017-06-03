#define LOG_TAG "LedService"

#include "ILedService.h"

#include <utils/Log.h>
#include <binder/IPCThreadState.h>
#include <binder/Parcel.h>
#include <unistd.h>

namespace android {

// ----------------------------------------------------------------------

class BpLedService : public BpInterface<ILedService>
{
public:
    BpLedService(const sp<IBinder>& impl)
        : BpInterface<ILedService>(impl)
    {
    }

    virtual void ledOn(void)
    {
		printf("BpLedService::ledOn(void)\n");
        Parcel data, reply;
        remote()->transact(LED_ON, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(LedService, "android.os.ILedService");

// ----------------------------------------------------------------------

status_t BnLedService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch (code) {
        case LED_ON: {
               ledOn();
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
	}
}

}; // namespace android
