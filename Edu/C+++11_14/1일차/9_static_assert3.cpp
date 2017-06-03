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

// �����Լ��� ���� ��ü�� 0���� �ʱ�ȭ �ϵ��� ����
template<typename T> void xmemset(T* p, int value)
{
	static_assert(is_default_constructible<T>::value,
						"T has no default constructor");

	T obj; // ����Ʈ �����ڰ� �־�� �Ѵ�.

	// static_assert�� traits�� ���� ����ϸ� �����ϴ�.
	static_assert(is_polymorphic<T>::value == false,
				  "error, T has virtual function");

	memset(p, value, sizeof(T));
}

int main()
{
	Test t;
	xmemset(&t, 0);

//	memset(&t, 0, sizeof(Test)); // �̷��� �ص� �ɱ�� ?
//	t.foo();

}







