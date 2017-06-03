#if 1
#include <stdio.h>
#include <utils/Looper.h>

using namespace android;

class MyMessageHandler : public MessageHandler 
{
public:
    virtual void handleMessage(const Message& message)
	{
		sleep(3);
		printf("handleMessage(%d)\n", message.what);
	}
};

class MyThread : public Thread
{
		sp<Looper> mLooper;
		sp<MessageHandler> mHandler;
	public:
		MyThread( sp<Looper> &looper , sp<MessageHandler> &handler) 
			: mLooper(looper), mHandler(handler) {}

		bool threadLoop()
		{
			sleep(1);
			mLooper->sendMessage(mHandler, Message(1));
			printf("MyThread after\n");
			return false;
		}
};


int main()
{
	sp<MessageHandler> handler = new MyMessageHandler;
	sp<Looper> looper = new Looper(true);
	int result;
	sp<Thread> thread = new MyThread(looper, handler);
	thread->run();


	while(1)
	{
		result = looper->pollOnce(-1);

		if( result == Looper::POLL_TIMEOUT )
			printf("POLL_TIMEOUT\n");
		if( result == Looper::POLL_WAKE )
			printf("POLL_WAKE\n");
		if( result == Looper::POLL_CALLBACK )
			printf("POLL_CALLBACK\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <utils/Looper.h>

using namespace android;


class MyThread : public Thread
{
		sp<Looper> mLooper;
		int writeFd;
	public:
		MyThread( sp<Looper> &looper , int fd) : mLooper(looper), writeFd(fd) {}
		bool threadLoop()
		{
			sleep(1);
			write( writeFd, "W" , 1 );
			printf("MyThread after\n");
			return false;
		}
};

int my_handler(int fd, int events, void* data)
{
	sleep(3);
	printf("my_handler()\n");
	return 0;
}

int main()
{
	int fd[2];
	pipe(fd);
	sp<Looper> looper = new Looper(true);
	int result;
	sp<Thread> thread = new MyThread(looper, fd[1]);
	thread->run();

	looper->addFd( fd[0], Looper::POLL_CALLBACK, Looper::EVENT_INPUT , my_handler , 0 ); 

	while(1)
	{
		result = looper->pollOnce(-1);

		if( result == Looper::POLL_TIMEOUT )
			printf("POLL_TIMEOUT\n");
		if( result == Looper::POLL_WAKE )
			printf("POLL_WAKE\n");
		if( result == Looper::POLL_CALLBACK )
			printf("POLL_CALLBACK\n");
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <utils/Looper.h>

using namespace android;


class MyThread : public Thread
{
		sp<Looper> mLooper;
	public:
		MyThread( sp<Looper> &looper ) : mLooper(looper) {}
		bool threadLoop()
		{
			sleep(3);
			mLooper->wake();
			return false;
		}
};

int main()
{
	sp<Looper> looper = new Looper(true);
	int result;
	sp<Thread> thread = new MyThread(looper);
	thread->run();

	result = looper->pollOnce(-1);

	if( result == Looper::POLL_TIMEOUT )
		printf("POLL_TIMEOUT\n");
	if( result == Looper::POLL_WAKE )
		printf("POLL_WAKE\n");

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <utils/Looper.h>

using namespace android;

int main()
{
	sp<Looper> looper = new Looper(true);
	int result;

	looper->wake();
	result = looper->pollOnce(-1);

	if( result == Looper::POLL_TIMEOUT )
		printf("POLL_TIMEOUT\n");
	if( result == Looper::POLL_WAKE )
		printf("POLL_WAKE\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <utils/Looper.h>

using namespace android;

int main()
{
	sp<Looper> looper = new Looper(true);

	int result;

	result = looper->pollOnce(3000);

	if( result == Looper::POLL_TIMEOUT )
		printf("POLL_TIMEOUT\n");

	return 0;
}
#endif














