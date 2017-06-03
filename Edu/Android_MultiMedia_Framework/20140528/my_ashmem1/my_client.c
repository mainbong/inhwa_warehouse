#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>

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
	char *p=0;

	bs = binder_open(128*1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}

	handle = svcmgr_lookup(bs, svcmgr, argv[1]);
	fprintf(stderr,"lookup(%s) = %x\n", argv[1], handle);

    bio_init(&msg, iodata, sizeof(iodata), 4);
    binder_call(bs, &msg, &reply, handle, 1);
	fd = bio_get_fd( &reply );
	printf("fd=%d\n", fd );

	p = (char*)mmap( 0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("p=%p\n", p );
	printf( "%s\n", p );
	munmap( p, 4096);
	close(fd);
	return 0;
}







