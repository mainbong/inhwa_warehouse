#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "binder.h"

uint32_t svcmgr_lookup(struct binder_state *bs, uint32_t target, const char *name)
{
    uint32_t handle;
    unsigned iodata[512/4];
    struct binder_io msg, reply;

    bio_init(&msg, iodata, sizeof(iodata), 4);
    bio_put_uint32(&msg, 0);  // strict mode header
    bio_put_string16_x(&msg, SVC_MGR_NAME);
    bio_put_string16_x(&msg, name);

    if (binder_call(bs, &msg, &reply, target, SVC_MGR_CHECK_SERVICE))
        return 0;

    handle = bio_get_ref(&reply);

    if (handle)
        binder_acquire(bs, handle);

    binder_done(bs, &msg, &reply);

    return handle;
}



int main(int argc, char **argv)
{
	int fd;
	struct binder_state *bs;
	uint32_t svcmgr = BINDER_SERVICE_MANAGER;
	uint32_t handle;
    unsigned iodata[512/4];
    struct binder_io msg, reply;

	bs = binder_open(128*1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}

	handle = svcmgr_lookup(bs, svcmgr, argv[1]);
	fprintf(stderr,"lookup(%s) = %x\n", argv[1], handle);

    bio_init(&msg, iodata, sizeof(iodata), 4);

    binder_call(bs, &msg, &reply, handle, 1);
    binder_call(bs, &msg, &reply, handle, 2);
	return 0;
}
