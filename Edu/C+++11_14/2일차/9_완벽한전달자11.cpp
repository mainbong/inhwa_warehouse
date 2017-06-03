// �Ϻ��������� 1�� �����ؿ�����

#include <iostream>
using namespace std;

void foo(int&& a) { cout << "foo" << endl; }

// rvalue�� rvalue�� lvalue�� lvalue�� ĳ�����ϴ� �Լ�
template<typename T> T&& xforward(T&& a)
{
	return static_cast<T&&>(a);
}
template<typename F, typename T> void logTime(F f, T&& a)
{
	// �Ʒ� �ڵ�� ���ڷ� rvalue�� ���� : static_cast<int&&>(a)
	//				    lvalue�� ���� : static_cast<int&>(a) 

	// ��, "���ڰ� rvalue��� rvalue�� lvalue��� lvalue�� ĳ�����ϴ� �ڵ��Դϴ�."
	//f(static_cast<T&&>(a));

	// T&& a ���� 10�� ������
	// T&& : int&&
	// a   : lvalue �Դϴ�.
	//f(xforward(a)); // a�� lvalue �̹Ƿ� xforward�� T&& => int& 

	// �׷��� �ݵ�� ����� �߷��� ����ؾ� �մϴ�.
	//f(xforward<T&&>(a));
	f(forward<T&&>(a));
}



int main()
{
	foo(10); // ok �ƹ� ���� ����.

	logTime(foo, 10); // ?? �� �ȵɱ�� ??
					  // T&& => int&& a
						// int&& r = 10; // 10�� rvalue ���� 
										// r�� lvalue �̴�.
}






