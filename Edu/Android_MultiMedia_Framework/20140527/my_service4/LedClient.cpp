#include "LedClient.h"

namespace android {
	void LedClient::dataCallback(int ratio)
	{
		printf("LedClient::dataCallback(%d)\n", ratio);
	}
};
