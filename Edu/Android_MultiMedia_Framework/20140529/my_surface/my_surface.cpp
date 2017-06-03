#include <media/mediaplayer.h>
#include <media/IMediaPlayer.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <utils/String8.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>
#include <gui/Surface.h>

using namespace android;

void fillRGBA8BufferSolid(uint8_t* buf, int w, int h, int stride, uint8_t r,
		uint8_t g, uint8_t b, uint8_t a) {
	const size_t PIXEL_SIZE = 4;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < h; x++) {
			off_t offset = (y * stride + x) * PIXEL_SIZE;
			buf[offset + 0] = r;
			buf[offset + 1] = g;
			buf[offset + 2] = b;
			buf[offset + 3] = a;
		}
	}
}

int main(int argc, char **argv)
{
	sp <Surface> gsf;
	status_t nState;

	printf("create SurfaceComposerClient\n");

	sp<SurfaceComposerClient> composerClient;
	sp<SurfaceControl> control;

	composerClient = new SurfaceComposerClient;
	composerClient->initCheck();

	printf("create video surface\n");

	control = composerClient->createSurface(
			String8("A Surface"),
			1280,
			800,
			PIXEL_FORMAT_RGBA_8888,
			0);

	SurfaceComposerClient::openGlobalTransaction();
	control->setLayer(INT_MAX);
	control->show();
	SurfaceComposerClient::closeGlobalTransaction();


	sp<ANativeWindow> window;
	window = control->getSurface();

	ANativeWindowBuffer *anb;
	native_window_dequeue_buffer_and_wait(window.get(), &anb);

	sp<GraphicBuffer> buf(new GraphicBuffer(anb, false));

	uint8_t* img = NULL;
	while(1)
	{
		buf->lock(GRALLOC_USAGE_SW_WRITE_OFTEN, (void**)(&img));
		printf("width=%d, height=%d, stride=%d\n", 
				buf->getWidth(), buf->getHeight(), buf->getStride());
		fillRGBA8BufferSolid(img, buf->getWidth(), buf->getHeight(), buf->getStride(), 255, 0, 0, 255);
		buf->unlock();
		window->queueBuffer(window.get(), buf->getNativeBuffer(), -1);
	}



	return 0;
}

