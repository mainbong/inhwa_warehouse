#if 1
#include <stdio.h>

class RefBase
{
		int mRef;
	public:
		void incStrong() { ++mRef; }
		void decStrong() { if( --mRef == 0 )  delete this ; }
		RefBase():mRef(0){}
		virtual ~RefBase(){}
};

class AAA : public RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *ptr;
public : 
	sp(T *_ptr=0): ptr(_ptr) { if( ptr != 0 ) ptr->incStrong(); }
	sp( const sp<T> &r ): ptr(r.ptr) { if( ptr != 0 ) ptr->incStrong(); }
	~sp() { ptr->decStrong(); }
	T *operator->() { return ptr; }
	T &operator*() { return *ptr; }
};


int main()
{
	{
		sp<AAA> p1  = new AAA;
		sp<AAA> p2  = p1;
		sp<AAA> p3  = p1;
		sp<AAA> p4  = p1;
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	static int ref;
	T *ptr;
public : 
	sp(T *_ptr=0): ptr(_ptr) { if( ptr != 0 ) ++ref; }
	sp( const sp<T> &r ): ptr(r.ptr) { if( ptr != 0 ) ++ref; }
	~sp() { if( --ref == 0 ) delete ptr; }
	T *operator->() { return ptr; }
	T &operator*() { return *ptr; }
};

template < typename T >
int sp<T>::ref = 0;

int main()
{
	{
		sp<AAA> p1  = new AAA;
		sp<AAA> p2  = p1;
		sp<AAA> p3  = p1;
		sp<AAA> p4  = p1;
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *ptr;
public : 
	sp(T *_ptr=0): ptr(_ptr) {}
	~sp() { delete ptr; }
	T *operator->() { return ptr; }
	T &operator*() { return *ptr; }
};

int main()
{
	{
		sp<AAA> p1  = new AAA;
		sp<AAA> p2  = p1;
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *ptr;
public : 
	sp(T *_ptr=0): ptr(_ptr) {}
	~sp() { delete ptr; }
	T *operator->() { return ptr; }
	T &operator*() { return *ptr; }
};

int main()
{
	{
		sp<AAA> p1  = new AAA;
		sp<AAA> p2  = p1;
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *ptr;
public : 
	sp(T *_ptr=0): ptr(_ptr) {}
	~sp() { delete ptr; }
	T *operator->() { return ptr; }
	T &operator*() { return *ptr; }
};

int main()
{
	{
		sp<AAA> p  = new AAA;
		p->foo();   // (p.operator->())->foo();
		(*p).foo(); // (p.operator*()).foo();
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void foo(){ printf("AAA::foo()\n"); }
};

class sp
{
	AAA *ptr;
public : 
	sp(AAA *_ptr=0): ptr(_ptr) {}
	~sp() { delete ptr; }
	AAA *operator->() { return ptr; }
	AAA &operator*() { return *ptr; }
};

int main()
{
	{
		sp p  = new AAA;
		p->foo();   // (p.operator->())->foo();
		(*p).foo(); // (p.operator*()).foo();
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

class sp
{
	AAA *ptr;
public : 
	sp(AAA *_ptr=0): ptr(_ptr) {}
	~sp() { delete ptr; }
};

int main()
{
	{
		sp p  = new AAA;
	}

	return 0;
}
#endif


#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	while(1)
	{
		AAA *p = new AAA;
		getchar();
	}

	return 0;
}
#endif
