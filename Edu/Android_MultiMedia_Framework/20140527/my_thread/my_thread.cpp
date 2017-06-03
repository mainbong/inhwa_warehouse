#if 0
#include <unistd.h>
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>
#include <utils/Thread.h>

using namespace android;

// pthread_create
class AAA : public Thread 
{
	public :
		status_t   readyToRun()
		{
			printf("AAA::readyToRun()\n");
			return NO_ERROR;
		}
		bool  threadLoop()
		{
			printf("AAA::threadLoop()\n"); 
			sleep(1);
			return true;
		}
};

int main()
{
	sp<Thread> p = new AAA;
	p->run();
	printf("main()\n");
	getchar();
	return 0; 
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>
#include <utils/Thread.h>

using namespace android;

class AAA : public Thread 
{
	public :
		status_t   readyToRun()
		{
			printf("AAA::readyToRun()\n");
			return NO_ERROR;
		}
		bool  threadLoop()
		{
			printf("AAA::threadLoop()\n"); 
			sleep(1);
			return true;
		}
};

int main()
{
	sp<Thread> p = new AAA;
	p->run();
	printf("main()\n");
	getchar();
	return 0; 
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>
#include <utils/Thread.h>

using namespace android;

class AAA : public Thread 
{
	public :
		bool  threadLoop()
		{
			printf("AAA::threadLoop()\n"); 
			sleep(1);
			return true;
		}
};

int main()
{
	sp<Thread> p = new AAA;
	p->run();
	printf("main()\n");
	getchar();
	return 0; 
}
#endif


#if 0
#include <unistd.h>
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>
#include <utils/Thread.h>

using namespace android;

class AAA : public Thread 
{
	public :
		bool  threadLoop()
		{
			printf("AAA::threadLoop()\n"); 
			sleep(3);
			return true;
		}
};

int main()
{
	AAA *p = new AAA;
	p->run();
	//p->threadLoop();
	printf("main()\n");
	getchar();
	return 0; 
}
#endif


#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>
#include <utils/Thread.h>

using namespace android;

class AAA : public Thread 
{
	public :
		bool  threadLoop()
		{
			printf("AAA::threadLoop()\n"); 
			return true;
		}
};

int main()
{
	AAA *p = new AAA;
	//p->run();
	p->threadLoop();
	getchar();
	return 0; 
}
#endif
