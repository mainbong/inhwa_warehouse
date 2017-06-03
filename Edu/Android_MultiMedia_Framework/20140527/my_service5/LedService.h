#ifndef ANDROID_LED_SERVICE_H
#define ANDROID_LED_SERVICE_H

#include <binder/BinderService.h>
#include "ILedService.h"

namespace android {


class LedService : 
    public BinderService<LedService>,
	public BnLedService
{
public:
    static const char* getServiceName() { return "led.service"; }
    virtual void ledOn(void);
};

};
#endif
