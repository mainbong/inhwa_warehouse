//12_과제
#include "show.h"
#include <map>
using namespace placeholders;

void foo(void* p)			{ cout << "foo " << (int)p << endl; }
void goo(void* p, int n)	{ cout << "goo " << (int)p << endl; } 

class CallbackTable
{
	typedef function<void(void*)> HANDLER;
	map<string, vector<HANDLER>> callbacks;
public:
	inline void Register(string action, HANDLER callback, int priority = 1) 
	{ 
		callbacks[action].push_back(callback); 
	}	
	void Fire(string action, void* input) {
		vector<HANDLER>& v = callbacks[action];
		for (int i = 0; i < v.size(); i++)
		{
			v[i](input); // function 이므로 ()로 호출...
		}
	}
};

int main()
{
	//CallbackTable 만들어보세요..
	CallbackTable ct;

	ct.Register("DISCONNECT_WIFI", &foo, 2);
	ct.Register("DISCONNECT_WIFI", bind(&goo, _1, 0), 1);
	ct.Register("LOW_POWER", &foo);
	
	ct.Fire("DISCONNECT_WIFI", (void*)30);
}