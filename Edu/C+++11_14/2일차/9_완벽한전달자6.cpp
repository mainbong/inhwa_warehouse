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

// Ŭ���� ���ø��� T�� �Ͻ��� �߷��� �Ұ����ؼ� �׻� ��ƽ��ϴ�.
// �Ͻ��� �߷��� ������ �Լ� ���ø��� ���۷� �����մϴ�.
template<typename T> 
xreference_wrapper<T> xref(T& a)
{
	return xreference_wrapper<T>(a);
}



int main()
{
	int n = 0;

//	xreference_wrapper<int> r(n);
//	logTime(goo, r);
	//logTime(goo, xreference_wrapper<int>(n)); // �ӽð�ü ���
	
	logTime(goo, ref(n) ); // ���� ����!!!!! �ᱹ ������ �������� �̷��� �մϴ�.
						   // C# : logTime( ref n)

	cout << n << endl;
}




/*
template<typename T> T square(T a) { return a * a; }

// ������ ���� �ڵ�� ?
square(3);      // 1. T�� �����Ϸ��� �߷� - ����.
square<int>(3); // 2. T�� ����ڰ� ���� - ����� ���δ�.


list<int> s(10, 3); //10���� 3���� �ʱ�ȭ
*/











