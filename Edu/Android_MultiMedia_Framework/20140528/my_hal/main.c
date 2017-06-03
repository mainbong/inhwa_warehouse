#include <stdio.h>
#include <dlfcn.h>
#include "main.h"

int main()
{
	char buff[] = "1234";
	int  value;
	void *handle;
	struct device_t *hal;

	handle = dlopen("libatoi.so", RTLD_LAZY);
	hal = dlsym( handle, "HAL");
	value = hal->atoi(buff);
	hal->add(&value);
	dlclose(handle);

	printf("%d\n", value );
	return 0;
}

