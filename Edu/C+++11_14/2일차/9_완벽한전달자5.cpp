// 9_완벽한전달자 - 106page
#include <iostream>
using namespace std;

template<typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}
	operator T&() { return *obj; }
};

void foo(int a) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 10; }

template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

int main()
{
	int n = 0;

	logTime(foo, 10);
	//logTime(goo, n);

	// 참조로 전달하려면 xreference_wrapper에 묶어서 보낸다.
	xreference_wrapper<int> r(n);
	logTime(goo, r);
//	logTime(goo, &n); // 결국 위 코드와 아래 코드는 모두 n의 주소를 보냅니다.
				  // 하지만 r은 xreference_wrapper<> 이므로 int& 로 변환 가능하고..
				  // &n 은 int* 이므로 int&로 변환 불가능합니다.
	
					// 결국 xreference_wrapper는 int&로 변환 가능한 포인터입니다.
	cout << n << endl; 
}



