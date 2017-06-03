#include <iostream>
#include <type_traits>
#include <string.h>
using namespace std;

class Test
{
	int data;
public:
	virtual void foo() {}
};

// 가상함수가 없는 객체만 0으로 초기화 하도록 하자
template<typename T> void xmemset(T* p, int value)
{
	static_assert(is_default_constructible<T>::value,
						"T has no default constructor");

	T obj; // 디폴트 생성자가 있어야 한다.

	// static_assert와 traits를 같이 사용하면 좋습니다.
	static_assert(is_polymorphic<T>::value == false,
				  "error, T has virtual function");

	memset(p, value, sizeof(T));
}

int main()
{
	Test t;
	xmemset(&t, 0);

//	memset(&t, 0, sizeof(Test)); // 이렇게 해도 될까요 ?
//	t.foo();

}







