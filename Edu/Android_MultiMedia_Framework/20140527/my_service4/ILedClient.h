#ifndef ANDROID_ILED_CLIENT_H
#define ANDROID_ILED_CLIENT_H

#include <binder/IInterface.h>
#include <binder/IPermissionController.h>
#include <utils/Vector.h>
#include <utils/String16.h>

namespace android {

// ----------------------------------------------------------------------

class ILedClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(LedClient);

    virtual void         dataCallback( int ) = 0;

    enum {
        DATA_CALLBACK = IBinder::FIRST_CALL_TRANSACTION
    };
};

// ----------------------------------------------------------------------------

class BnLedClient : public BnInterface<ILedClient>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};
// ----------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_ILED_CLIENT_H

