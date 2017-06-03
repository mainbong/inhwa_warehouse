#include "LedService.h"

namespace android {
	void LedService::connect(sp<ILedClient> &ledClient)
	{
		printf("LedService::ledOn(void)\n");
		ledClient->dataCallback(123);
	}
};
