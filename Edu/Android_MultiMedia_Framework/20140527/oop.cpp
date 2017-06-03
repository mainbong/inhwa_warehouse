#if 1
#include <stdio.h>
class AAA
{
	int data;
public:
	static void _threadLoop( void *self ) 
	{
		((AAA*)self)->threadLoop();
	}
	void threadLoop() 
	{
		printf("threadLoop()\n");
	}
};

int main()
{
	AAA a;
	AAA::_threadLoop(&a);
	return 0;
}
#endif


#if 0
#include <stdio.h>
class AAA
{
	int data;
public:
	static void _threadLoop() 
	{
		threadLoop();
	}
	void threadLoop() 
	{
		printf("threadLoop()\n");
	}
};

int main()
{
	AAA::_threadLoop();
	return 0;
}
#endif
#if 0
#include <stdio.h>
class AAA
{
	int data;
public:
	static void foo() 
	{
		printf("AAA::foo()\n");
	}
};

int main()
{
	AAA::foo();
	void (*p)() = &AAA::foo;
	(*p)();
	return 0;
}
#endif
#if 0
#include <stdio.h>
class AAA
{
	int data;
public:
	void foo()  // AAA::foo
	{
		printf("AAA::foo()\n");
	}
};

int main()
{
	AAA a;
	a.foo();  // AAA::foo(&a);
	void (AAA::*p)() = &AAA::foo;
	(a.*p)();
	return 0;
}
#endif
