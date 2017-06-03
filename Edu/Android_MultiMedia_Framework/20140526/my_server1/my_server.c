#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "binder.h"

int svcmgr_publish(struct binder_state *bs, uint32_t target, const char *name, void *ptr)
{
    int status;
    unsigned iodata[512/4];
    struct binder_io msg, reply;

    bio_init(&msg, iodata, sizeof(iodata), 4);
    bio_put_uint32(&msg, 0);  // strict mode header
    bio_put_string16_x(&msg, SVC_MGR_NAME);
    bio_put_string16_x(&msg, name);
    bio_put_obj(&msg, ptr);

    if (binder_call(bs, &msg, &reply, target, SVC_MGR_ADD_SERVICE))
        return -1;

    status = bio_get_uint32(&reply);

    binder_done(bs, &msg, &reply);

    return status;
}

unsigned token;

int my_handler(struct binder_state *bs,
		       struct binder_transaction_data *txn,
			   struct binder_io *msg, struct binder_io *reply)
{
    switch(txn->code) {
    case 1 :
		printf("SERVER : LED_ON\n");
		break;
    case 2 :
		printf("SERVER : LED_OFF\n");
		break;
	}
    return 0;
}

int main(int argc, char **argv)
{
    int fd;
    struct binder_state *bs;
    uint32_t svcmgr = BINDER_SERVICE_MANAGER;
    uint32_t handle;

    bs = binder_open(128*1024);
    if (!bs) {
        fprintf(stderr, "failed to open binder driver\n");
        return -1;
    }

    svcmgr_publish(bs, svcmgr, argv[1], &token);
	binder_loop( bs, my_handler );
    return 0;
}
