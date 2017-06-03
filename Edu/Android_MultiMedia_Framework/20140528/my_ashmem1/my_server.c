#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#include "binder.h"

#define __ASHMEMIOC		0x77
#define ASHMEM_SET_SIZE		_IOW(__ASHMEMIOC, 3, size_t)


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
int fd;

int my_handler(struct binder_state *bs,
		       struct binder_transaction_data *txn,
			   struct binder_io *msg, struct binder_io *reply)
{
	switch(txn->code) {
		case 1 :
			{
				bio_put_fd(reply, fd);
			}
			break;
	}
	return 0;
}

int main(int argc, char **argv)
{
    struct binder_state *bs;
    uint32_t svcmgr = BINDER_SERVICE_MANAGER;
    uint32_t handle;
	char *p=0;

	fd = open("/dev/ashmem", O_RDWR );
	printf("fd=%d\n", fd );
	ioctl(fd, ASHMEM_SET_SIZE, 4096);

	p = (char*)mmap( 0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("p=%p\n", p );
	sprintf( p , "Hello Android!!");

    bs = binder_open(128*1024);
    if (!bs) {
        fprintf(stderr, "failed to open binder driver\n");
        return -1;
    }

    svcmgr_publish(bs, svcmgr, argv[1], &token);
	binder_loop( bs, my_handler );
    return 0;
}






