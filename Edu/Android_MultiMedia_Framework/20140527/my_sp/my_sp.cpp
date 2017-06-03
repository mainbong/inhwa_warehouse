#if 1
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo()   // void foo( AAA *this )
		{ 
			data = 10;  // this->data = 10;
			printf("AAA::foo()\n"); 
		}
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void onFirstRef()
		{
			printf("AAA::onFirstRef()\n");
		}
};

int main()
{
	{
		wp<AAA> p = new AAA;        
		p->foo();
	}
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo()   // void foo( AAA *this )
		{ 
			data = 10;  // this->data = 10;
			printf("AAA::foo()\n"); 
		}
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void onFirstRef()
		{
			printf("AAA::onFirstRef()\n");
		}
};

int main()
{
	{
		wp<AAA> p1;
		{
			sp<AAA> p2 = new AAA;        
			p1 = p2;
		}
		if( p1.promote() != 0 )
			p1.promote()->foo();   // foo(p1);
		else
			printf("객체가 소멸됨\n");
	}
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo(){ printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
		void onFirstRef()
		{
			printf("AAA::onFirstRef()\n");
		}
};

int main()
{
	{
		sp<AAA> p = new AAA;        
	}
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo(){ printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		wp<AAA> p1 = new AAA;             // void *p1 = new AAA;
		sp<AAA> p2 = p1.promote();        // AAA *p2 = (AAA*)p1;
	}
	return 0; 
}
#endif

#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo(){ printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		wp<AAA> p1 = new AAA;   // void *p1 = new AAA;
		sp<AAA> p2 = (AAA*)p1;        // AAA *p2 = (AAA*)p1;

	}
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo(){ printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;   // AAA *p1 = new AAA;
		wp<AAA> p2 = p1;        // void *p2 = p1;

		*p1;
	}
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		int data;
		void foo(){ printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		//wp<AAA> p = new AAA;
		void *p = new AAA;   // void * => weak pointer 

		//p->foo();
		p->data = 10;
		// (*p).data = 10;
	}
	return 0; 
}
#endif


#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		wp<AAA> p1;
		{
			sp<AAA> p2 =  new AAA;
			p1 = p2;
		}
		printf("step 1.\n");
	}
	printf("step 2.\n");
	return 0; 
}
#endif

#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		sp<AAA> p1;
		{
			sp<AAA> p2 =  new AAA;
			p1 = p2;
		}
		printf("step 1.\n");
	}
	printf("step 2.\n");
	return 0; 
}
#endif


#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		wp<AAA> p1 = new AAA;
	}
	printf("after\n");
	return 0; 
}
#endif



#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class BBB;

class AAA : public RefBase
{
	public :
	    wp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

class BBB : public RefBase
{
	public :
		wp<AAA> pa;
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB(){ printf("BBB::~BBB()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<BBB> p2 = new BBB;
		p1->pb = p2;
		p2->pa = p1;
	}
	printf("after\n");
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class BBB;

class AAA : public RefBase
{
	public :
	    sp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

class BBB : public RefBase
{
	public :
		sp<AAA> pa;
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB(){ printf("BBB::~BBB()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<BBB> p2 = new BBB;
		p1->pb = p2;
		p2->pa = p1;
	}
	printf("after\n");
	return 0; 
}
#endif
#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		void foo() { printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1;
		sp<AAA> p3 = p1;
		sp<AAA> p4 = p1;
	}
	printf("after\n");
	return 0; 
}
#endif

#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		void foo() { printf("AAA::foo()\n"); }
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		sp<AAA> p = new AAA;
		p->foo();
		(*p).foo();
	}
	printf("after\n");
	return 0; 
}
#endif


#if 0
#include <stdio.h>
#include <utils/StrongPointer.h>
#include <utils/RefBase.h>

using namespace android;

class AAA : public RefBase
{
	public :
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA(){ printf("AAA::~AAA()\n"); }
};

int main()
{
	{
		sp<AAA> p = new AAA;
	}
	printf("after\n");
	return 0; 
}
#endif
