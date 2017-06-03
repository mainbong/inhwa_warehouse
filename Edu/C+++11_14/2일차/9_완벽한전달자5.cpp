// 9_�Ϻ��������� - 106page
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

	// ������ �����Ϸ��� xreference_wrapper�� ��� ������.
	xreference_wrapper<int> r(n);
	logTime(goo, r);
//	logTime(goo, &n); // �ᱹ �� �ڵ�� �Ʒ� �ڵ�� ��� n�� �ּҸ� �����ϴ�.
				  // ������ r�� xreference_wrapper<> �̹Ƿ� int& �� ��ȯ �����ϰ�..
				  // &n �� int* �̹Ƿ� int&�� ��ȯ �Ұ����մϴ�.
	
					// �ᱹ xreference_wrapper�� int&�� ��ȯ ������ �������Դϴ�.
	cout << n << endl; 
}



