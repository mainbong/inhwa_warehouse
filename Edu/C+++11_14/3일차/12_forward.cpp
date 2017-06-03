// 12_forward
#include <iostream>
using namespace std;

// ���� �ҽ��� �Ϻ��� ������ 11��..forward()�����ؿ����� - �̸��� xforward�� �����ϼ���

template<typename T> T&& xforward(T& a) // int& & => int&
{										// int&& & => int&&

	// �� ����ڰ� lvalue ĳ������ �䱸�ϸ� forward<int& &&>(a)
	//            rvalue ĳ������ �䱸�ϸ� forward<int&& &&>(a) �� �˴ϴ�.
	return static_cast<T&&>(a); // int& &&
								// int&& &&
}

template<typename F, typename T> void logTime(F f, T a)
{
	// ���ڰ� lvalue �̸� T�� : int&
	//        rvalue     T   : int&& 
	//						������ int&& a �� a�� _lvalue__
	f(xforward<T>(a));
}

void foo(int a) {}

int main()
{
	logTime(foo, 10);
}