#ifndef ANDROID_LED_CLIENT_H
#define ANDROID_LED_CLIENT_H

#include "ILedClient.h"

namespace android {


class LedClient : public BnLedClient
{
public:
    virtual void dataCallback(int);
};

};
#endif
